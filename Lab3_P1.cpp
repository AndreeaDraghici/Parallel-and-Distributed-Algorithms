#include <iostream>
#include <string.h>
#include <mpi.h>

#define idToSearch 4
#define noOfStudents 10
#define MASTER 0

typedef struct {

    char name[25];
    int studentId;

}student;

int main(int argc, char** argv)
{
    int rank;
    int size;

    student students[10];
    char name[10][25] = { "georgiana", "andreea", "liviu", "beti", "claudia", "mihai", "ionut", "ciprian","andrei","magdalena" };
    int ids[10] = { 1,3,5,8,12,11,14,8,4,10 };
    int blockcounts[2];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);/* get own identifier */
    MPI_Comm_size(MPI_COMM_WORLD, &size);/* get nr of processes */

    MPI_Status status;
    MPI_Aint offsets[2];

                                /*derived data types*/
    MPI_Datatype Datatypes[2] = { MPI_CHAR, MPI_INT };

    /*define the struct student with name and id*/
    offsets[0] = offsetof(student, name); 
    offsets[1] = offsetof(student, studentId);

    MPI_Datatype studentType;

    blockcounts[0] = 1;
    blockcounts[1] = 1;

    /*created structured type and commit it 
    can contain multiple data types*/
    MPI_Type_create_struct(2, blockcounts, offsets, Datatypes, &studentType);
    MPI_Type_commit(&studentType);

    for (int i = 0; i < noOfStudents; i++){
        strcpy_s(students[i].name, name[i]);
        students[i].studentId = ids[i];
    }

    int length = noOfStudents / size; // numbers per rank
    /* set the limit for rank */
    int start = rank * length;
    int stop = rank * length + length;

    /* sending the list of students*/
    MPI_Bcast(&students, noOfStudents, studentType, MASTER, MPI_COMM_WORLD);

    bool found = false;
    int index = 0;

    /*search the student*/
    for (int i = start; i <= stop; i++){
        if (students[i].studentId == idToSearch){
            found = true;
            index = i;
            break;
        }
    }

    /*print the id if it found, and the name of student*/
    if (found){
        std::cout << "The rank " << rank << " was found the student with the id " << idToSearch << " and his/her name is \"" << students[index].name << "\" at position " << index << std::endl;
    }
    else{
        std::cout << "The rank " << rank << " was not found the student with the id " << idToSearch << std::endl;
    }

    MPI_Finalize();
}