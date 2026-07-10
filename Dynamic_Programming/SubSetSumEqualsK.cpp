#include<iostream>
#include<vector>
using namespace std;

bool f(vector<int>& arr, int ind, int target){

    if (target == 0) return true;
    if (ind == 0) return arr[ind] = target;

    bool take = false;
    bool notTake = f(arr, ind-1, target);
    if (target >= arr[ind]){
        take = f(arr, ind-1, target-arr[ind]);
    }

    return take | notTake;

}

bool f2(vector<int>& arr, int ind, int target, vector<vector<int>>& DP){

    if (target == 0) return true;
    if (ind == 0) return arr[ind] = target;

    if (DP[ind][target] != -1) return DP[ind][target];

    bool take = false;
    bool notTake = f2(arr, ind-1, target, DP);
    if (target >= arr[ind]){
        take = f2(arr, ind-1, target-arr[ind], DP);
    }

    return DP[ind][target] = take | notTake;

}

bool f3(vector<int>& arr, int n, int k){

    vector<vector<int>> dp(n, vector<int> (k+1, -1));

    for (int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i<n; i++){
        for (int t=0; t<k; t++){
            bool take = false;
            bool notTake = dp[i-1][t];
            if (t >= arr[i]){
                take = dp[i-1][t];
            dp[i][t] = take | notTake;
            }

        }
    }
    return dp[n-1][k];

}

int main(){

    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int k = 4;

    bool ans = f(arr, n-1, 4);

    if (ans) cout << endl << "Hip Hip HURRAY! \nWe found" << endl;
    else cout << "We couldn't find" << endl;
    
    vector<vector<int>> DP(n, vector<int> (k+1, -1));
    bool ans2 = f2(arr, n-1, 4, DP);
    if (ans2) cout << endl << "Hip Hip HURRAY! \nWe found" << endl;
    else cout << "We couldn't find" << endl;

    bool ans3 = f3(arr, n, k);
    if (ans3) cout << endl << "we found using TABU!!" << endl; 
    else cout << "WE ARE SORRY!" << endl;
 
    
    return 0;
}