// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaX-sigmaY) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take 4 inputs: sigmaX, sigmaY, tauXY, theta
// output transformed stresses: sigmaX', sigmaY', tauXY'
//
// NOTE: perform the transformation inside a function that cannot be named main
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void tranStress(float sigmaX,float sigmaY,float tauXY,float theta,float *sigmaXTa,float *sigmaYTa,float *tauXYTa);
int main (int argc, char **argv) {
	if (argc != 5) {
		printf("need 5 arguments");
		exit(-1);
	}
	float sigmaX=atof(argv[1]);
	float sigmaY=atof(argv[2]);
	float tauXY=atof(argv[3]);
	float theta=atof(argv[4]);
        
//	float sX=0;
//	float sY=0;
//	float tXY=0;
//	float *sigmaXT=&sX;
//	float *sigmaYT=&sY;
//	float *tauXYT=&tXY;
//
//	tranStress(sigmaX,sigmaY,tauXY,theta,sigmaXT,sigmaYT,tauXYT);
//	printf("transformed stresses are %f %f %f\n",*sigmaXT,*sigmaYT,*tauXYT);
	float sigmaXT=0;
	float sigmaYT=0;
	float tauXYT=0;

	tranStress(sigmaX,sigmaY,tauXY,theta,&sigmaXT,&sigmaYT,&tauXYT);
        printf("transformed stresses are %f %f %f\n",sigmaXT,sigmaYT,tauXYT);
return 0;	
}
void tranStress(float sigmaX,float sigmaY,float tauXY,float theta,float * sigmaXTa,float * sigmaYTa,float *tauXYTa) {
*sigmaXTa=sigmaX*cos(theta)*cos(theta)+sigmaY*sin(theta)*sin(theta);
*sigmaYTa=sigmaX*sin(theta)*sin(theta);
*tauXYTa=(sigmaX-sigmaY);
}
