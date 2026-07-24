#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 10, 8, 9};
    int n = arr.size();
    vector<int> DP(n, 1);

    int maxi = 0;

    for (int i=0; i<n; i++){
        for (int prev=0; prev<i; prev++){
            if (arr[prev] < arr[i] && 1 + DP[prev] > DP[i]){
                DP[i] = 1+DP[prev];
            }        
        }
        if (DP[i] > maxi) maxi = DP[i];
    }

    for (int i=0; i<n; i++){
        cout << DP[i] << " ";
    }
    cout << endl;
    // int count = 0;
    // for(int i=0; i<n; i++){
    //     if (DP[i] == maxi) count++; 
    // }
    // cout << count << endl;

    return 0;
}