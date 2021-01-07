#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <stdlib.h>

static long int numSteps = 1000000000;

int main() {
  // perform calculation
  double piFinal=0;
  double dx=1./numSteps;
  #pragma omp parallel reduction(+:piFinal)
  {
     int tid=omp_get_thread_num();
     int numT=omp_get_num_threads();
  
     double pi   = 0;
     for (int i=tid; i<numSteps; i+=numT) {
        double x=(i+0.5)*dx;
        pi += 4./(1.+x*x);
     } 
     pi *= dx;
  
     piFinal+=pi;
  }
  printf("PI = %16.14f Difference from math.h definition %16.14f \n",piFinal, piFinal-M_PI);
  return 0;
}
