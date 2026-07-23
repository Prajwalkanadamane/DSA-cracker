#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int f0(int idx, int prev, int arr[], int n){

    if (idx == n) return 0;

    
    int take = 0, dontT = 0;

    dontT = 0 + f0(idx+1, prev, arr, n);
    if ( prev == -1 || arr[idx] > arr[prev]){
        take = 1 + f0(idx+1, idx, arr, n);
    }

    return max(take, dontT);

}

int f1(int idx, int prev, int arr[], int n, vector<vector<int>>& DP){

    if (idx == n) return 0;

    if (DP[idx][prev+1] != -1) return DP[idx][prev+1];
    int take = 0, dontT = 0;

    dontT = 0 + f1(idx+1, prev, arr, n, DP);
    if (prev == -1 || arr[idx] > arr[prev]){
        take = 1 + f1(idx+1, idx, arr, n, DP);
    }

    return DP[idx][prev+1] = max(take, dontT);

}

int longestIncreasingSubsequence(int arr[], int n){

    int idx = 0, prev = -1;
    vector<vector<int>> DP(n+1, vector<int>(n+1, 0));

    for (int idx = n-1; idx>=0; idx--){
        for (int prev = idx-1; prev>=-1; prev--){
            int DontT = 0, take = 0;

            DontT = 0 + DP[idx+1][prev+1];
            if (prev == -1 || arr[prev] < arr[idx]){
            take = 1 + DP[idx+1][idx+1];
            }
            DP[idx][prev+1] = max(take, DontT);
        }
    }

    return DP[0][0];
}

int solution(int arr[], int n){

    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for (int i=1; i<n; i++){
        if (arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    return len;
}

int main(){

    int arr[] = {5, 4, 11, 1, 16, 8};
    vector<vector<int>> DP(6, vector<int>(7, -1));
    

    cout << "longest Increasing Subsequence: the recursive approach: " << f0(0, -1, arr, 6) << endl;
    cout << "longest Increasing Subsequence: the recursive approach MEMO: " << f1(0, -1, arr, 6, DP) << endl;

    // cout << "longest Increasing Subsequence O(n)optimized: " << solution(arr, 6) << endl;
    // cout << "longest Increasing Subsequence: " << longestIncreasingSubsequence(arr, 6) << endl;

    // vector<int> DP(6, 1);
    // int maxi = 1;
    // for (int i=0; i<6; i++){
    //     for (int j=0; j<i; j++){
    //         if (arr[i] > arr[j]){
    //             DP[i] = max (DP[i], 1 + DP[j]);
    //         }
    //     }
    //     maxi = max(maxi, DP[i]);
    // }

    // cout << "longest Increasing Subsequence using loops: " << maxi << endl;

    return 0;
}