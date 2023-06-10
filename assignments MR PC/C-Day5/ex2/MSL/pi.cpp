#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// static long int numSteps = 1000000000;

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Error correct usage: app numSteps\n");
    return 0;
  }
  int numSteps = (int)(argv[1]);

  // perform calculation
  double pi   = 0;
  double dx = 1./numSteps;
  double x; // = dx*0.50;
  // double M_PI = 0;

  double contribution[64];
  for (int i=0; i<64; i++)
    contribution[i] = 0;
  
  omp_set_num_threads(1);
  #pragma omp parallel
  {
    double mycontr = 0;
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    for (int i=tid; i<numSteps; i+=numT) {
      x = (i+0.5)*dx;
      mycontr += 4./(1.+x*x);
    }
    contribution[tid] = mycontr;

  }

  for (int i=0; i<64; i++) 
    pi += contribution[i];
  
  printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  return 0;
}
