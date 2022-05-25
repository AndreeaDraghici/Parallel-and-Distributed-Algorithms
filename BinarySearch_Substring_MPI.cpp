//#include <iostream>
//#include "mpi.h"
//#include<cstdlib>
//
//using namespace std;
//
//#define MASTER 0
//
//void computeLPSArray(char* pat, int M, int* lps);
//
//// Prints occurrences of txt[] in pat[]
//void KMPSearch(char* pat, int M, int N, char* txt, int rank)
//{
//    M = strlen(pat);
//    N = strlen(txt);
//
//    // create lps[] that will hold the longest prefix suffix
//    // values for pattern
//    int* lps = new int[M];
//
//    // Preprocess the pattern (calculate lps[] array)
//    computeLPSArray(pat, M, lps);
//
//    int i = 0; // index for txt[]
//    int j = 0; // index for pat[]
//    while (i < N) {
//        if (pat[j] == txt[i]) {
//            j++;
//            i++;
//        }
//
//        if (j == M) {
//            printf("Found pattern at index %d ", i - j);
//            cout << "Element is  found by processor " << rank << "\n";
//            j = lps[j - 1];
//            return;
//        }
//
//        // mismatch after j matches
//        else if (i < N && pat[j] != txt[i]) {
//            // Do not match lps[0..lps[j-1]] characters,
//            // they will match anyway
//            if (j != 0)
//                j = lps[j - 1];
//            else
//                i = i + 1;
//        }
//    }
//}
//
//// Fills lps[] for given patttern pat[0..M-1]
//void computeLPSArray(char* pat, int M, int* lps)
//{
//    // length of the previous longest prefix suffix
//    int len = 0;
//
//    lps[0] = 0; // lps[0] is always 0
//
//    // the loop calculates lps[i] for i = 1 to M-1
//    int i = 1;
//    while (i < M) {
//        if (pat[i] == pat[len]) {
//            len++;
//            lps[i] = len;
//            i++;
//        }
//        else // (pat[i] != pat[len])
//        {
//            // This is tricky. Consider the example.
//            // AAACAAAA and i = 7. The idea is similar
//            // to search step.
//            if (len != 0) {
//                len = lps[len - 1];
//
//                // Also, note that we do not increment
//                // i here
//            }
//            else // if (len == 0)
//            {
//                lps[i] = 0;
//                i++;
//            }
//        }
//    }
//}
//
//// Driver program to test above function
//int main(int argc, char** argv)
//{
//    char txt[] = "CDABABCABAB";
//    char pat[] = "ABABCA";
//
//    int n = strlen(txt);
//    int m = strlen(pat);
//
//
//    // KMPSearch(pat, txt);
//
//    MPI_Init(&argc, &argv); //initialize the MPI
//    int rank, size;
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    MPI_Status status;
//
//    cout << "Processor rank : " << rank << "\nSize : " << size << endl;
//
//    int blocks = 8;
//    int blockSize = n/blocks;
//    double start, stop;
//    
//    if (rank == 0) {
//        double start = MPI_Wtime();
//        KMPSearch(txt, rank * blockSize, (rank + 1) * blockSize - 1, pat,rank);
//        double end = MPI_Wtime();
//        cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//    }
//    else if (rank == 1) {
//        double start = MPI_Wtime();
//        KMPSearch(txt, rank * blockSize, (rank + 1) * blockSize - 1, pat, rank);
//        double end = MPI_Wtime();
//        cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//    }
//    else if (rank == 2) {
//        double start = MPI_Wtime();
//        KMPSearch(txt, rank * blockSize, (rank + 1) * blockSize - 1, pat, rank);
//        double end = MPI_Wtime();
//        cout << "Execution time of Processor " << rank << " is " << (end - start) * 1000 << endl;
//    }
//
//
//    MPI_Finalize();
//
//    return 0;
//}