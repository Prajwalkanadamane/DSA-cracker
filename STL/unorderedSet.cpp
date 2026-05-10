// 4. unordered_set (Hash Set)
// An unordered_set is a set that stores unique elements in any order (unordered).

// No duplicate elements.
// Faster than set because it uses Hash Table.
// Not ordered (Random order).
// Time Complexity: O(1) on average for insertion, deletion, and search.

#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> j;

    j.insert(1);
    j.insert(2);
    j.insert(3);
    j.insert(2);

    for (auto elem:j){
        cout << elem << " ";
    }
    return 0;
}