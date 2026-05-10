#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int tar, int st, int end){
    if (st<=end){
        int mid = st + (end-st)/2;

        if (arr[mid] == tar){
            return mid;
        }
        else if(arr[mid] <= tar){
            return BinarySearch(arr, tar, mid+1, end);
        }else{
            return BinarySearch(arr, tar, st, mid-1);
        }
    }
    return -1;
}

bool Search(vector<int> arr, int target){

    return BinarySearch(arr, target, 0, arr.size()-1);

}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int target  = 3;

    if (Search(arr,target)){
        cout << "found";
    }else{
        cout << "not found";
    }
    return 0;
}