#include<iostream>
#include<vector>
using namespace std;

int Solve(int n, vector<int>& arr){ // Recursion Approach

    if (n == 0) return arr[n];

    if (n < 0) return 0;

    int pick = arr[n] + Solve(n-2, arr);

    int notPick = 0 + Solve(n-1, arr);

    return max(pick, notPick);

}

int Solve2(int n, vector<int>& arr, vector<int>& DP){ // Tabulation Approach

    if (n == 0) return arr[n];

    if (n < 0) return 0;

    if (DP[n] != -1) return DP[n];

    int pick = arr[n] + Solve(n-2, arr);
    int notPick = 0 + Solve(n-1, arr);

    return DP[n] = max(pick, notPick);

}

int Solve3(int n, vector<int>& arr){

    vector<int> DP(n, 0);

    DP[0] = arr[0];

    for (int i=1; i<n; i++){

        int pick = arr[i]; if (i>1) pick += DP[i-2];
        int notPick = 0 + DP[i-1];

        DP[i] = max(pick, notPick);
    }
    return DP[n-1];

}

int Solve4(int n, vector<int>& arr){ //Space optimization

    int prev = arr[0];
    int prev2 = 0;

    for (int i=1; i<n; i++){

        int pick = arr[i]; if (i>1) pick += prev2;
        int notPick = 0 + prev;

        int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;

    }
    return prev;

}

int main(){

    vector<int> arr = {2, 1, 4, 9};

    int ans = Solve(arr.size()-1, arr);
    vector<int> DP(arr.size(), -1);

    cout << "Maximum Sum of Non-Adjacent Elements: " << ans << endl;

    cout << "Maximum Sum of Non-Adjacent Elements (Memorization): " << Solve2(arr.size()-1, arr, DP) << endl;

    cout << "Maximum Sum of Non-Adjacent Elements (Tabulation): " << Solve3(arr.size(), arr) << endl;

    cout << "Maximum Sum of Non-Adjacent Elements (Tabulation, Space Optimized): " << Solve4(arr.size(), arr) << endl;


    return 0;
}