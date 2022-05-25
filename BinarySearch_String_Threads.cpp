//#include <iostream>
//#include <pthread.h>
//
//using namespace std;
//
// //size of array
//#define MAX 16
//
// //maximum number of threads
//#define MAX_THREAD 4
//
//// array to be searched
//char a[] = {"are"};
//
// //key that needs to be searched
//char key = 'a';
//bool found = false;
//int part = 0;
//
//void* binary_search(void* arg)
//{
//
//     //Each thread checks 1/4 of the array for the key
//    int thread_part = part++;
//    int mid;
//
//    int low = thread_part * (MAX / 4);
//    int high = (thread_part + 1) * (MAX / 4);
//
//     //search for the key until low < high
//    // or key is found in any portion of array
//    while (low < high && !found) {
//
//      
//        mid = (high - low) / 2 + low;
//
//        if (a[mid] == key) {
//            found = true;
//            break;
//        }
//
//        else if (a[mid] > key)
//            high = mid - 1;
//        else
//            low = mid + 1;
//    }
//}
//
//int main()
//{
//    pthread_t threads[MAX_THREAD];
//
//    for (int i = 0; i < MAX_THREAD; i++)
//        pthread_create(&threads[i], NULL, binary_search, (void*)NULL);
//
//    for (int i = 0; i < MAX_THREAD; i++)
//        pthread_join(threads[i], NULL);
//
//    
//    if (found)
//        cout << key << " found in array" << endl;
//
//    
//    else
//        cout << key << " not found in array" << endl;
//
//    return 0;
//}