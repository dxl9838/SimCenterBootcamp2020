
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName inputFile\n");
    return -1;
  }
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      // some code needed here I think .. programming exercis
	maxVectorSize=2*maxVectorSize;
	double *vector3=(double *)malloc(maxVectorSize*sizeof(double));
	double *vector4=(double *)malloc(maxVectorSize*sizeof(double));
	for (int j=0;j<maxVectorSize/2;j++) {
		vector3[j]=vector1[j];
		vector4[j]=vector2[j];
	}
	free(vector1);
	free(vector2);
	double *vector1=vector3;
	double *vector2=vector4;
	vector3=0;
	vector4=0;
    }
    
  }

  fclose(filePtr);  
}
