//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <execution>
//using namespace std;
//
//string arrList[] = { "Geeks", "For", "GeeksForGeek" };
//
////iterative binary search
//int binary_search_iterative(vector<string> arr, string key)
//{
//    int left = 0, right = arr.size();
//
//    while (left <= right) {
//
//        int mid = left + (right - left) / 2;
//        if (arr[mid] == key)
//            return mid;
//        else if (arr[mid] < key)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return -1;
//}
//
////to print
//void print(vector<string>& a)
//{
//    for (auto it : a)
//        cout << it << " ";
//    cout << endl;
//}
//
//int main()
//{
//    cout << "Enter number of words you want to enter for the word list\n";
//    static int array;
//    cin >> array;
//
//  
//    vector<string> arr(array);
//    cout << "Enter the words\n";
//    for (int i = 0; i < array; i++) {
//        cin >> arr[i];
//    }
//
//
//    static string start;
//    static string end;
//
//    start = arrList[array - 1];
//    end = arrList[array];
//
//    cout << "Enter searching key\n";
//    //key there
//    string key;
//    cin >> key;
//
//    sort(arr.begin(), arr.end());
//
//    cout << "Printing the sorted word list\n";
//    print(arr);
//
//    clock_t tStart1 = clock();
//    int index = binary_search_iterative(arr, key);
//    if (index == -1)
//        cout << key << " not found\n";
//    else
//        cout << key << " found at index(0 based): " << index << endl;
//
//    std::for_each(std::execution::par, arr.begin(), arr.end(), [](string& x) {x = (std::rand() % (end - start)) + start; x = binary_search_iterative(x, array); });
//
//    return 0;
//}