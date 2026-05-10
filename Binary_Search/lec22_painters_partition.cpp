#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible (vector<int> &arr, int m ,int n, int maxallowedTime){

    int painter = 1, time = 0;

    for (int i=0; i<n; i++){

        if (time+arr[i] <= maxallowedTime){
            time += arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
    }
    return painter > m ? false:true;
}

int minimumTime(vector<int>& arr, int m, int n){
    if (m>n){
        return -1;
    }
    
    int start = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for (int i=0; i<n; i++){
        sum+=arr[i];
    }
    int end = sum;

    int ans = -1;
    while (start<=end){
        int mid = start + (end-start)/2;

        if(isPossible(arr,m,n,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20};
    int m = 2; // no. of painters
    int n = arr.size(); //no. of boards

    cout << "minimum time to paint maximum boards: " << minimumTime(arr,m,n);

    return 0;
}