
// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take:
// 1: 4 inputs: sigmaX, sigmaY, tauXY, theta and output transformed stresses: sigmaX', sigmaY', tauXY'
// 2: 3  inputs: sigmaX, sigmaY, tauXY and output transformed stresses: sigmaX', sigmaY', tauXY' for every 10 degrees
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *stressIN, float theta, float *stressTransformed);

int main(int argc, char **argv) {

  double sigmaX=0, sigmaY=0, tauXY=0, theta =0;

  // if (argc != 5 && argc != 4)  {
  //   printf("Usage: Three or Four Inputs required.\n");
  //   exit(-1);
  // }

  if (argc == 5){
    sigmaX = atof(argv[1]);
    sigmaY = atof(argv[2]);
    tauXY = atof(argv[3]);
    theta = atof(argv[4]);

    float stressIN[3] = {sigmaX, sigmaY, tauXY};
    float stressTransformed[3];
    transformStress(stressIN, theta, stressTransformed);

    printf("%.4f, %.4f, %.4f\n", stressTransformed[0], stressTransformed[1], stressTransformed[2]);
    // printf("%.4f, %.4f, %.4f\n", sigmaX, sigmaY, tauXY);

  }

  else if (argc == 4){
    sigmaX = atof(argv[1]);
    sigmaY = atof(argv[2]);
    tauXY = atof(argv[3]);

    float stressIN[3] = {sigmaX, sigmaY, tauXY};
    for(int i=0;i<=36;i++){
      float theta = i*10;
      float stressTransformed[3];
      transformStress(stressIN, theta, stressTransformed);
      printf("%.4f, %.4f, %.4f, %.4f\n", theta, stressTransformed[0], stressTransformed[1], stressTransformed[2]);
    }
  }
  return 0;
}

void transformStress(float *stressIN, float theta, float *stressTransformed){
  float sigmaX = stressIN[0];
  float sigmaY = stressIN[1];
  float tauXY = stressIN[2];

  float theta_rad = theta*M_PI/180;
  float cos_theta = cos(theta_rad);
  float sin_theta = sin(theta_rad);

  stressTransformed[0] = (sigmaX * cos_theta * cos_theta) + (sigmaY * sin_theta * sin_theta) + (2 * tauXY * sin_theta * cos_theta);
  stressTransformed[1] = (sigmaX * sin_theta * sin_theta) + (sigmaY * cos_theta * cos_theta) - (2 * tauXY * sin_theta * cos_theta);
  stressTransformed[2] = ((sigmaY-sigmaX) * sin_theta * sin_theta) - tauXY *(cos_theta * cos_theta - sin_theta * sin_theta);
}

