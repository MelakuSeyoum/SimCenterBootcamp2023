#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "ERROR correct usage appName inputFile outputBinaryFile" << endl;
    return -1;
  }

  //
  // read from ascii file
  // 
  ifstream inFile(argv[1]); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = new double[maxVectorSize];
  double *vector2 = new double[maxVectorSize];  
  int vectorSize = 0;
  
  while (inFile >> i >> float1 >> float2) {
    vector1[vectorSize] = static_cast<double>(float1);
    vector2[vectorSize] = static_cast<double>(float2);
    cout << i << ", " << vector2[i] << ", " << vector1[i] << endl;
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      
      // create new arrys & copy contents
      double *newVector1 = new double[2*vectorSize];
      double *newVector2 = new double[2*vectorSize];
      for (int i=0; i<vectorSize; i++) {
  newVector1[i]=vector1[i];
  newVector2[i]=vector2[i];
      }

      // release old memory, set vectors to point to new ones and update max vector size
      delete[] vector1;
      delete[] vector2;
      vector1 = newVector1;
      vector2 = newVector2;
      maxVectorSize *= 2;
    }
  }
  inFile.close();

  //
  // write to binary file
  //
  
  ofstream outFile(argv[2], ios::binary);
  outFile.write(reinterpret_cast<char*>(vector1), sizeof(double) * vectorSize);
  outFile.write(reinterpret_cast<char*>(vector2), sizeof(double) * vectorSize);    
  outFile.close();  
  delete[] vector1;
  delete[] vector2;
}