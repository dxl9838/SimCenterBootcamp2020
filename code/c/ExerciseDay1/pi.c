// calculate pi numerically
//
// pi = integral 0->1 (4/(1+x^2))dX
//
// compute an approx using sum from i = 1 to N
// of F(xi)delta X, where F(xi) computed at middle of iterval i
//
// take as input the number of intervals N
//
#include <stdio.h>
static int long numSteps=100000;
int main() {
double pi=0;
double dx=1./numSteps;
double x=dx*0.5;

for (int i=0;i<numSteps;i++){
pi+=4./(1.+x*x);
x+=dx;
}
pi*=dx;
printf("PI=%16.14f\n",pi);
return 0;
}
