#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {5, 4, 11, 1, 16, 8};

    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hashi(n, 0);
    int maxi = 1, lastidx = 0;

    for (int i=0; i<n; i++){
        hashi[i] = i;
        for (int prev=0; prev<i; prev++){
            if (arr[prev] < arr[i] && 1+dp[prev] > dp[i]){
                dp[i] = dp[prev]+1;
                hashi[i] = prev;
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            lastidx = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastidx]);

     while(hashi[lastidx] != lastidx){
        lastidx = hashi[lastidx];
        temp.push_back(arr[lastidx]);
     }

    reverse(temp.begin(), temp.end());
    
    for (int i=0; i<temp.size(); i++){
        cout << temp[i] << " ";
    }

    return 0;
}