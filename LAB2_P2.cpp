//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include "mpi.h"
//using namespace std;
//
//#define ArraySIZE 500
//#define SEARCHED_ELEMENT 20
//#define MASTER 0
//
//int main(int argc, char** argv)
//{
//	int size, rank, sendCount, recvCount, PositionOfElement = 0;
//	int arr[ArraySIZE];
//	int position[ArraySIZE / 2], allPositions[ArraySIZE / 2];
//	int receiveBuffer[ArraySIZE / 2];
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);/* get own identifier */
//	MPI_Comm_size(MPI_COMM_WORLD, &size); /* get nr of processes */
//
//	int id = 0;
//	for (int value = 0; value < ArraySIZE; value++) {
//		arr[value] = id;
//		id++;
//		if (id == 101) {
//			id = 0;
//		}
//	}
//
//	sendCount = ArraySIZE / size; /* send buffer */
//	recvCount = ArraySIZE / size; /* receive buffer */
//	MPI_Scatter(arr, sendCount, MPI_INT, receiveBuffer, recvCount, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	PositionOfElement = 0;
//	for (int count = 0; count < recvCount; count++) {
//		if (receiveBuffer[count] == SEARCHED_ELEMENT) {
//			/* each process initializes its local position */
//			position[PositionOfElement] = rank * recvCount + count;
//			PositionOfElement++;
//		}
//	}
//
//	int maxPosition = 0;
//	MPI_Reduce(&PositionOfElement, &maxPosition, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
//	/* the array position from all proceses, place it in all positions */
//	MPI_Gather(&position, PositionOfElement, MPI_INT, &allPositions, PositionOfElement, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	if (rank == MASTER) {
//		if (maxPosition <= 0) {
//			printf("\nThe element was not found!\n");
//		}
//		else {
//			printf("\nThe element was found on the positions:");
//			/* print out all positions */
//			for (int i = 0; i < maxPosition; i++) {
//				printf(" %d ", allPositions[i]);
//			}
//			printf("\n");
//		}
//	}
//	MPI_Finalize();
//}