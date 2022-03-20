//#include <iostream>
//#include <stdlib.h> 
//#include <mpi.h>
//
//int main()
//{
//	MPI_Init(NULL, NULL);
//
//	int rank, size, value[101], recv[5], sum = 0;
//
//	MPI_Status status;
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	if (rank == 0) {
//
//		int partialSum;
//		for (int i = 1; i < size; i++) {
//			MPI_Recv(&partialSum, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
//			sum += partialSum;
//		}
//	}
//	else {
//
//		double start = MPI_Wtime();
//		int sum = 0;
//		for (int i = 0; i < 99; i++) {
//			value[i] = rand() % 1000;
//			sum += value[i];
//		}
//		printf("The sum of this process is: %i \n", sum);
//
//		MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
//
//		double end = MPI_Wtime();
//
//		printf("The process took %f \n", end - start);
//
//	}
//
//	MPI_Finalize();
//}