#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
  int numDivision = atoi(argv[1]);
  double delta_x = 1.0/numDivision;
  double pi   = 0;
  for (int i = 0; i<numDivision;i++){
    double x = (i*delta_x)+(delta_x/2);
    double F_at_x = 4/(1+x*x);
    pi = pi + F_at_x*delta_x;
  }
  printf("PI = %16.14f, diff(%16.14f)\n",pi, fabs(pi-M_PI));
  return 0;
}
