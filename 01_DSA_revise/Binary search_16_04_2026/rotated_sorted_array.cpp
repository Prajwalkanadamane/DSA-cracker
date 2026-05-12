#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>& arr, int tar){

    int st = 0;
    int end = arr.size()-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if (arr[mid] == tar){
            return true;
        }

        if (arr[st] <= arr[mid]){
            if (arr[st]<= tar && tar<= arr[mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }else{
            if (arr[mid] <= tar && tar<= arr[end]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
    }
    return false;

}

int main(){
    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int tar1 = 2;

    bool ans = solve(arr, tar1);
    if (ans){
        cout << tar1 << " found.";
    }else{
        cout << tar1 << " not found.";
    }

    return 0;
}