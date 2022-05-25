//#include <algorithm>
//#include <iostream>
//#include <execution>
//#include <random>
//#include <vector>
//
//using namespace std;
//
//int arrayList[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
//
//void display(int &arr, int arraysize)
//{
//    for (int i = 0; i < arraysize; i++)
//        cout << arr<< ", ";
//}
//
//int MybinarySearch(int &arr, int size)
//{
//    cout << "\nThe array is : \n";
//    display(arr, size);
//
//    // sort string array a for binary search as prerequisite
//    sort(arr, arr + size);
//    if (binary_search(arrayList, arrayList + 10, 2)) {    
//         cout << "\nElement found in the array";
//    }
//    else {
//        cout << "\nElement not found in the array";
//    }
//}
//
//
//int main()
//{
//    static int array;
//    cin >> array;
//
//    vector<int> arr(array);
//
//    static int start = 1;
//    static int end = 1;
//    start = arrayList[array-1];
//    end = arrayList[array];
//
//    cout << "\nThe array is : \n";
//    std::for_each(std::execution::par, arr.begin(), arr.end(), [](int& x) {x = (std::rand() % (end - start)) + start; x = MybinarySearch(x, array); });
//    for (int i = 0; i < arr.size(); i++) {
//
//        std::cout << arr[i] << " , ";
//    }
//    return 0;
//}