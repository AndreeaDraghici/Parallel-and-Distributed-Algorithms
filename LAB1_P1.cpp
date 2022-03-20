//#include <iostream>
//#include "mpi.h"
//#include <cstdlib>
//#include <cmath>
//#include <vector>
//#include <stdio.h>
//
//#define _CRT_SECURE_NO_DEPRECATE
//#define MAXIMAL_VALUE 30
//
//using namespace std;
//
//
//bool checkPrimeNumber(int n) {
//	bool isPrime = true;
//	if (n == 0 || n == 1) {
//		isPrime = false;
//	}
//	else {
//		for (int i = 2; i <= n / 2; ++i) {
//			if (n % i == 0) {
//				isPrime = false;
//				break;
//			}
//		}
//	}
//	return isPrime;
//}
//
//int main(int argc, char** argv)
//{
//	MPI_Init(NULL, NULL);
//
//	int rank, size, value[26], recv[5], primeNumbers[5];
//
//
//	MPI_Status status;
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	if (rank == 0) {
//		printf("Elements of the vector are: ");
//		for (int i = 0; i < 25; i++) {
//			value[i] = rand() % 25;
//			printf(" %i", value[i]);
//		}
//
//		printf("\n");
//		int k = 0;
//		for (int i = 1; i < size; i++) {
//			MPI_Send(&value[k], 5, MPI_INT, i, 1, MPI_COMM_WORLD);
//			k += 5;
//		}
//	}
//	else {
//		MPI_Recv(&recv, 5, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
//		int primeNumbersFromRecv[5];
//		int index = 0;
//
//		for (int i = 0; i < 5; i++) {
//			if (checkPrimeNumber(recv[i]) == true && recv[i] <= MAXIMAL_VALUE) {
//				primeNumbersFromRecv[index] = recv[i];
//				index++;
//			}
//		}
//
//		printf("The prime number: ");
//		for (int i = 0; i < index; i++) {
//			printf(" %i", primeNumbersFromRecv[i]);
//		}
//		printf("\n");
//
//	}
//
//	MPI_Finalize();
//}