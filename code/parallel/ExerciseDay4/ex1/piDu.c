#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define LUMP 500

int main(int argc, char **argv) {
  
  int numP, procID;

  // the usual mpi initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  double *globalData=NULL;
  double localData=0;

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = (double *)malloc(numP * sizeof(double) );
    for (int i=0; i<numP; i++)
      globalData[i] = 0;
  }

  double dx=1./(LUMP*numP);
  double x=1./numP*(procID-1)+dx*0.50;
  for (int i=0; i<LUMP; i++) {
    //localData[i] = procID*10+i;
    localData+=4./(1.+x*x);
    x+=dx;
  }

  MPI_Gather(&localData, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if (procID == 0) {
    double pi=0;
    for (int i=0; i<numP; i++) {  
	pi+=globalData[i];		
    }
    pi*=dx;
    printf("%f ", pi);
    printf("\n");
  }

  if (procID == 0)
    free(globalData);

  MPI_Finalize();
}
