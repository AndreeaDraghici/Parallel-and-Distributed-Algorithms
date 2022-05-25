//#include <algorithm>
//#include <iostream>
//#include <functional> // searchers
//#include <iomanip>    // quoted
//
//int main() {
//    std::string string = "Hello Super World";
//    std::string substring = "Super";
//
//    std::cout << "Looking for " << std::quoted(substring)<< " in " << std::quoted(string) << '\n';
//
//    auto found = search(string.begin(), string.end(),
//        std::boyer_moore_searcher(substring.begin(), substring.end()));
//
//    if (found != string.end()){
//        std::cout << "Found at position " << std::distance(string.begin(), found) << '\n';
//    }
//    else {
//        std::cout << "...not found\n";
//    }
//}