//#include "mpi.h"
//#include <iostream>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//
//    int rank, size, sendBuff[8] = { 1,2,3,4,5,6,7,10 }, recvBuff = 0;
//    MPI_Group origGroup, prodGroup, sumGroup, maxGroup, minGroup;
//    MPI_Comm prodComm, sumComm, maxComm, minComm;
//
//    int ranks1[2] = { 0, 1 };
//    int ranks2[2] = { 2, 3 };
//    int ranks3[2] = { 4, 5 };
//    int ranks4[2] = { 6, 7 };
//
//    int current_sum = 0, current_prod = 0, current_max = 0, current_min = 0;
//
//    MPI_Init(&argc, &argv);
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);/* get own identifier */
//    MPI_Comm_size(MPI_COMM_WORLD, &size);/* get nr of processes */
//
//
//    /*extract the original group handle*/
//    MPI_Comm_group(MPI_COMM_WORLD, &origGroup);
//
//    /*include a set of processes into a new group:*/
//    MPI_Group_incl(origGroup, 2, ranks1, &sumGroup);
//    MPI_Group_incl(origGroup, 2, ranks2, &maxGroup);
//    MPI_Group_incl(origGroup, 2, ranks3, &prodGroup);
//    MPI_Group_incl(origGroup, 2, ranks4, &minGroup);
//
//    /*create new new communicator and then perform collective communications*/
//    MPI_Comm_create(MPI_COMM_WORLD, sumGroup, &sumComm);
//    MPI_Comm_create(MPI_COMM_WORLD, maxGroup, &maxComm);
//    MPI_Comm_create(MPI_COMM_WORLD, prodGroup, &prodComm);
//    MPI_Comm_create(MPI_COMM_WORLD, minGroup, &minComm);
//
//    /*divide tasks into two distinct groups based upon rank */
//    if (rank < 2) {
//        MPI_Comm_rank(sumComm, &current_sum);
//    }
//    else if (rank >= 2 && rank < 4) {
//        MPI_Comm_rank(maxComm, &current_max);
//    }
//    else if (rank >= 4 && rank < 6) {
//        MPI_Comm_rank(prodComm, &current_prod);
//    }
//    else if (rank >= 6) {
//        MPI_Comm_rank(minComm, &current_min);
//    }
//
//    if (rank < 2) {
//        MPI_Allreduce(&sendBuff, &recvBuff, 1, MPI_INT, MPI_SUM, sumComm);
//        printf("recvbuff = %d, sum comm rank = %i, worldrank = %i", recvBuff, current_sum, rank);
//    }
//    if (rank >= 2 && rank < 4) {
//        MPI_Allreduce(&sendBuff, &recvBuff, 1, MPI_INT, MPI_MAX, maxComm);
//        printf("recvbuff = %d, max comm rank = %i, worldrank = %i", recvBuff, current_max, rank);
//    }
//    if (rank >= 4 && rank < 6) {
//        MPI_Allreduce(&sendBuff, &recvBuff, 1, MPI_INT, MPI_PROD, prodComm);
//        printf("recvbuff = %d, prod comm rank = %i, worldrank = %i", recvBuff, current_prod, rank);
//    }
//    if (rank >= 6) {
//        MPI_Allreduce(&sendBuff, &recvBuff, 1, MPI_INT, MPI_MIN, minComm);
//        printf("recvbuff = %d, min comm rank = %i, worldrank = %i", recvBuff, current_min, rank);
//    }
//
//    MPI_Finalize();
//}