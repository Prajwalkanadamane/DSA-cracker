// 2. unordered_map (Hash Map)

// An unordered_map is a key-value pair data structure that stores elements in any order (unordered).

// Uses a Hash Table for faster access.
// Keys are unique.
// Not ordered (Random order).
// Time Complexity: O(1) on average for insertion, deletion, and search.
//  Example:

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

    unordered_map<string,int> fruits;

    fruits["apple"] = 5;
    fruits["mango"] = 3;
    fruits["banana"] = 1;

    for (auto elem:fruits){
        cout<< elem.first << " : " <<elem.second << endl;
    }

    return 0;
}