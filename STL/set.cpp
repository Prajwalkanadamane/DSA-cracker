//  3. set (Ordered Set)
// A set is a data structure that stores unique elements in sorted order.

// No duplicate elements.
// Sorted order by default (ascending order).
// Time Complexity: O(log N) for insertion, deletion, and search (because it uses a Red-Black Tree).
//  Example:

#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> j;

    j.insert(1);
    j.insert(2);
    j.insert(3);
    j.insert(2);

    for (auto elem:j){
        cout << elem << " ";
    }
    return 0;
}