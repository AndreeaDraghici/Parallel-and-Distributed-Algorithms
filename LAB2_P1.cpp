#include <iostream>
#include <stdlib.h>
#include <mpi.h>

#define SEARCHED_ELEMENT 7
#define MASTER 0
#define ArraySIZE 10

int main(int argc, char** argv) {

	int rank, size, position = -1, MaxPosition = -1;
	int arr[ArraySIZE] = { 1,9,6,5,7,3,8,10,2,4 };

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);/* get own identifier */
	MPI_Comm_size(MPI_COMM_WORLD, &size);/* get nr of processes */

	if (rank == MASTER) {
		printf("\nArray is: ");
		for (int i = 0; i <= 9; i++) {
			printf("%i ", arr[i]);
		}
	}
	/* sending the array */
	MPI_Bcast(&arr, ArraySIZE, MPI_INT, MASTER, MPI_COMM_WORLD);

	int distribution = ArraySIZE / size; // numbers per rank

	int lowBoundry = rank * distribution; // from
	int highBoundry = lowBoundry + distribution; // to

	for (int i = lowBoundry; i < highBoundry; i++) {
		if (arr[i] == SEARCHED_ELEMENT) {
			position = i;
			break;
		}
	}
	printf("\n");

	/* compute the maximum position, */
	MPI_Reduce(&position, &MaxPosition, 1, MPI_INT, MPI_MAX, MASTER, MPI_COMM_WORLD);
	if (rank == MASTER) {
		printf("Max position where the element is found is: %i ", MaxPosition);
	}

	MPI_Finalize();
}