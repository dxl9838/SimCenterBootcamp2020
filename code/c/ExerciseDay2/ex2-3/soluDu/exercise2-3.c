#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!
	if (argc!=2) {
		printf("please input an interval\n");
		exit(-1);
	}	
	// might be smart to set a default value, just in case the user
	// forgets when calling this  program;)
	float dth=atof(argv[1]);
	// set the initial stress state

	STRESS S0;
	STRESS Sp;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;

	// loop to compute transformed states
	double theta=0.0;
	for (theta=0.0;theta<=180.;theta+=dth) {
		StressTransform(S0, &Sp, theta);
		printf("%12.6f,%12.6f,%12.6f,%12.6f\n",theta,  Sp.sigx, Sp.sigy, Sp.tau);
	}
}

