// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  float delta;
  delta=pow(b,2)-4.0*a*c;
  if (delta<0.0) {
     printf("delta must be positive");
} else {
  float soln1=-b/2.0/a+sqrt(delta)/2.0/a;
  float soln2=-b/2.0/a-sqrt(delta)/2.0/a;
  printf("solutions are %f %f\n",soln1,soln2);
}
  printf("Have a Nice Day!\n");
  return 0;
}

