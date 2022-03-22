#include "mpi.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv) {

    int rank, size, sendBuff[8] = { 1,2,3,4,5,6,7,10 }, recvBuff;

    int ranks1[2] = { 0, 1 };
    int ranks2[2] = { 2, 3 };
    int ranks3[2] = { 4, 5 };
    int ranks4[2] = { 6, 7 };

    MPI_Comm newComm;
    MPI_Group origGroup, newGroup;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);/* get own identifier */
    MPI_Comm_size(MPI_COMM_WORLD, &size);/* get nr of processes */

    /*extract the original group handle*/
    MPI_Comm_group(MPI_COMM_WORLD, &origGroup);
  
    /*divide tasks into two distinct groups based upon rank */
    if (rank < 2) {

        /*include a set of processes into a new group*/
        MPI_Group_incl(origGroup,2, ranks1, &newGroup);
    }
    else if  (rank >= 2 && rank < 4) {

        MPI_Group_incl(origGroup,2, ranks2, &newGroup);
    }
    else if (rank >= 4 && rank < 6) {
        
        MPI_Group_incl(origGroup,2, ranks3, &newGroup);
    }
    else if(rank >= 6) {

        MPI_Group_incl(origGroup,2, ranks4, &newGroup);
    }

    /*create new new communicator and then perform collective communications*/
    MPI_Comm_create(MPI_COMM_WORLD, newGroup, &newComm);

    int sendValue = sendBuff[rank];
    
     MPI_Allreduce(&sendValue, &recvBuff, 1, MPI_INT, MPI_MAX, newComm);
     printf("Max is %d\n", recvBuff);

     MPI_Allreduce(&sendValue, &recvBuff, 1, MPI_INT, MPI_MIN, newComm);
     printf("Min is %d\n", recvBuff);

     MPI_Allreduce(&sendValue, &recvBuff, 1, MPI_INT, MPI_SUM, newComm);
     printf("Sum is %d\n", recvBuff);

     MPI_Allreduce(&sendValue, &recvBuff, 1, MPI_INT, MPI_PROD, newComm);
     printf("Prod is %d\n", recvBuff);
   
    MPI_Finalize();
}