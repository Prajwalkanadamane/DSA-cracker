#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& arr, int L, int R){

    vector<int> prefixSum(arr.size(), 0);
    prefixSum[0] = arr[0];

    for (int i=1; i<arr.size(); i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    if (L == 0){
        return prefixSum[R];
    }else{
        return prefixSum[R] - prefixSum[L-1];
    }

}

int main(){

    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << solve(arr, 0, 3) << endl;

    return 0;
}