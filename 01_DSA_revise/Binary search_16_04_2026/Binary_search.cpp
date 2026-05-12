#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>& arr, int tar){

    int st = arr[0];
    int end = arr.size()-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if (tar > arr[mid]){
            st = mid+1;
        }else if (tar < arr[mid]){
            end = mid-1;
        }else{
            return true;
        }
    }
    return false;

}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 2;

    bool ans = solve(arr, tar1);
    if (ans){
        cout << tar1 << " found.";
    }else{
        cout << tar1 << " not found.";
    }

    return 0;
}