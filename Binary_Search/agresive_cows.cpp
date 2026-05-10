#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int N, int c , int minallowedDistance){
    int cows = 1, laststallpos = arr[0];

    for (int i=1; i<N; i++){
        if (arr[i]-laststallpos >= minallowedDistance){
            cows++;
            laststallpos = arr[i];  

        }
        if (cows == c){
            return true;
        }
    }
    return false;
}

int getDistance (vector<int>& arr,int c, int N){
    sort(arr.begin(),arr.end());
    int start = 0,end = arr[N-1] - arr[0], ans = -1;

    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if (isPossible(arr,N,c,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
    
}

int main(){
    vector<int> arr = {1,2,8,4,9};
    int c = 3, N = 5;

    cout << getDistance(arr,c,N);

    return 0;
}