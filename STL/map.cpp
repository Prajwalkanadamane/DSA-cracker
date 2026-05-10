
#include <iostream>
#include <map>
using namespace std;

int main(){

    map<string, int> m;

    m["usn"] = 124;
    m["class"] = 1;
    m["abilities"] = 100;

    for (auto elem:m){
        cout << elem.first << ": " << elem.second << endl;
    }
    
    
    return 0;
}

// A map is a key-value pair data structure that stores elements in sorted order (based on keys).

// Keys are unique (No duplicate keys).
// Values can be duplicated.
// Ordered by default (sorted in ascending order of keys).
// Time Complexity: O(log N) for insertion, deletion, and search (because it uses a Red-Black Tree).