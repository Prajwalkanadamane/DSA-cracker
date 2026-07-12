#include<iostream>
#include<vector>
using namespace std;

bool f3(vector<int>& arr, int n, int k){

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
    return dp[n-1][k];

}

int main(){

    vector<int> arr = {2, 3, 3, 3, 4, 5, 1};
    int n = arr.size();

    int totalSum = 0;
    for (int i=0; i<arr.size(); i++){
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0){
        cout << "FAILED" << endl;
        return 0;
    }

    if (f3(arr, n, totalSum/2)) cout << "EXIST " << endl;
    else cout << "NOT EXIST" << endl;

    return 0;
}