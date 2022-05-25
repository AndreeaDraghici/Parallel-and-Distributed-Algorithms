//#include <iostream>
//#include <pthread.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <time.h>
//
//#define max 4
//using namespace std;
//
//int count[max] = { 0 };
//string str, sub;
//
//void* str_seq_count(void* args)
//{
//    int value = *(int*)args;
//    int i, j, k, l1, l2, flag;
//
//    // calculating length of string 1
//    l1 = str.length();
//
//    // calculating length of substring
//    l2 = sub.length();
//
//    for (i = 0 + value; i < l1; i = i + max) {
//
//        flag = 0;
//        k = i;
//
//        for (j = 0; j < l2; j++) {
//
//            // flag=0;
//            if (sub[j] == str[k])
//                k++;
//            else {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 0)
//            count[value] += 1;
//    }
//}
//
//// Driver code
//int main()
//{
//    int sum = 0;
//    int x[max];
//    for (int a = 0; a < max; a++)
//        x[a] = a;
//
//    str = "prrrogramisprrrogramming";
//    sub = "rr";
//
//    cout << "Enter the main string: "
//        << str << endl;
//    cout << "Enter the sequence to search: "
//        << sub << endl;
//
//    int i, l1;
//
//    pthread_t tid[max];
//
//    for (i = 0; i < max; i++) {
//        pthread_create(&tid[i], NULL,
//            str_seq_count,
//            (void*)&x[i]);
//    }
//    for (i = 0; i < max; i++)
//        pthread_join(tid[i], NULL);
//    for (i = 0; i < max; i++)
//        sum = sum + count[i];
//    cout << "Frequency of substring: "
//        << sum;
//
//    return 0;
//}