#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target){
    int start = 0;
    int end  = arr.size()-1;

    while (start<=end){
        int mid = ((start + end)/2);

        if (target > arr[mid]){
            start = mid+1;
        }
        else if (target < arr[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }

    }
    return -1;
}

int main() {
    vector<int> arr = {8,11,99,639,782};
    int target = 4;

    int result = binarySearch(arr, target);
    if (result != -1) 
        cout << "Element found at index " << result << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}

// Recurrssive approach

// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch (vector<int> arr, int target, int start, int end){

//     if (start<=end){

//         int mid = ((start + end)/2);

//         if (target > arr[mid]){
//             return binarySearch(arr,target,mid+1,end);
//         }

//         else if (target < arr[mid]){
//             return binarySearch(arr,target,start,mid-1);
//         }

//         else{
//             return mid;
//         }

//     }
//     return -1;
// }

// int main() {
//     vector<int> arr = {8,11,99,639,782};
//     int target = 99;
//     int end = arr.size();
//     // int end  = arr.size()-1 

//     int result = binarySearch(arr, target,0,end);
//     if (result != -1) 
//         cout << "Element found at index " << result << endl;
//     else 
//         cout << "Element not found" << endl;

//     return 0;
// }