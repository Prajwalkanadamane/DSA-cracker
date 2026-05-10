#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i;  // Found element, return index
    }
    return -1;  // Not found
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    int x = 4;

    int result = linearSearch(arr, x);
    if (result != -1) 
        cout << "Element found at index " << result << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}
