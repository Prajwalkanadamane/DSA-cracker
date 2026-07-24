#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int> &arr, vector<vector<int>>& DP){

    if (i == j) return 0;
    if (DP[i][j] != -1) return DP[i][j];

    
    int mini = 1e9;
    for (int k=i; k<j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, DP) + f(k+1, j, arr, DP);
        mini = min(mini, steps);
    }
    return DP[i][j] = mini;
}

int main(){

    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    vector<vector<int>> DP(n, vector<int>(n, -1));
    cout << "Minimal cost to multiply is: " << f(1, n-1, arr, DP) << endl;
    return 0;
}