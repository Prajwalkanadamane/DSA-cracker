#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>& arr, int tar, int st, int end){

    
    if (st <= end){
        int mid = st + (end - st)/2;
        if (tar > arr[mid]){
            return solve(arr, tar, mid+1, end);
        }else if (tar < arr[mid]){
            return solve(arr, tar, st, mid-1);
        }else{
            return true;
        }
    }
    return false;

}

int main(){
    vector<int> arr = {-1, 0, 3, 5, 9 ,12};
    int tar = 10;
    int st = 0;
    int end = arr.size()-1;
    bool ans = solve(arr, tar, st, end);

    if (ans){
        cout << tar << " found.";
    }else{
        cout << tar << " not found.";
    }
    return 0;
}