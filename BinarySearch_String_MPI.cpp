////#include <iostream>
////#include "mpi.h"
////#include<cstdlib>
////using namespace std;
//
//void binarySearch(char* arr, int left, int right, char key, int rank)
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] == key)
//		{
//			cout << "Element is  found by processor " << rank << "\n";
//			return;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//}
//int main(int argc, char** argv) {
//
//	char n = 'are';
//	char* arr = new char[n];
//
//	char key = 'a'; //element to search
//
//	//auto found = key.find(a);
//
//	for (int i = 0; i < n; i++){
//
//			arr[i] = i + 1;
//	}
//
//	MPI_Init(&argc, &argv);
//
//	int rank, size;
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	int blocks = 2;
//	int blockSize = n/blocks;
//
//
//	if (rank == 0)
//	{
//		double start = MPI_Wtime();
//		binarySearch(arr, rank * blockSize, (rank + 1) * blockSize - 1, key, rank);
//		double end = MPI_Wtime();
//		cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//	}
//	else if (rank == 1)
//	{
//		double start = MPI_Wtime();
//		binarySearch(arr, rank * blockSize, (rank + 1) * blockSize - 1, key, rank);
//		double end = MPI_Wtime();
//		cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//	}
//	else if (rank == 2)
//	{
//		double start = MPI_Wtime();
//		binarySearch(arr, rank * blockSize, (rank + 1) * blockSize - 1, key, rank);
//		double end = MPI_Wtime();
//		cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}