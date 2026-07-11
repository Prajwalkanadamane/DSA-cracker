#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){

    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    
    int totalSum = 0;
    for (int i=0; i<arr.size(); i++){
        totalSum += arr[i];
    }

    int k = totalSum;

    vector<vector<int>> dp(n, vector<int> (k+1, -1));

    for (int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i<n; i++){
        for (int t=0; t<=k; t++){
            bool take = false;
            bool notTake = dp[i-1][t];
            if (t >= arr[i]){
                take = dp[i-1][t-arr[i]];
            }
            dp[i][t] = take | notTake;

        }
    }
    
    int mini = 1e8;
    for (int s1=0; s1<=k/2; s1++){
        if (dp[n-1][s1] == true){
            int s2 = totalSum - s1; 
            mini = min(mini, abs(s2 - s1));
        }

    }
    cout << "Partition A Set Into Two Subsets With Minimum Absolute Sum Difference: " << mini << endl;

    return 0;
}