//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include"mpi.h"
//#include<queue>
//
//using namespace std;
//
//#define N 10
//#define FIND 3
//
//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//int find(int left, int right) {
//    for (int i = left; i < right; i++)
//    {
//        if (a[i] == FIND)
//            return i;
//    }
//    return 0;
//}
//
//
//int main(int argc, char* argv[])
//{
//    int idForProcess, numberOfProcesses, lengthPerProcess;
//    MPI_Status status;
//    MPI_Init(&argc, &argv);
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &idForProcess);
//    MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);
//
//    lengthPerProcess = N / numberOfProcesses;
//
//    if (idForProcess != 0) {
//        int result = find(idForProcess * lengthPerProcess, (idForProcess + 1) * lengthPerProcess);
//        MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//    }
//    else {
//        int result = 0;
//        for (int i = 1; i < numberOfProcesses; i++) {
//
//            MPI_Recv(&result, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//
//
//            if (result != 0) {
//                cout << "Found at index [ " << result << " ]" << endl;
//            }
//            else {
//                cout << "Not found" << endl;
//            }
//        }
//    }
//    MPI_Finalize();
//
//    return 0;
//}
//
//
