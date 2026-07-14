#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i, vector<int>& arr, int target){

    if (i == 0) {
        if (target % arr[i] == 0){
            return target / arr[i];
        }
        return 1e9;
    }

    int notPick = 0 + f(i-1, arr, target);
    int pick = 1e9;
    if (target >= arr[i]) pick = 1 + f(i, arr, target-arr[i]);

    return min(pick, notPick);

}

int f2(int i, vector<int>& arr, int target, vector<vector<int>>& DP){

    if (i == 0) {
        if (target % arr[i] == 0){
            return target / arr[i];
        }
        return 1e9;
    }
    if (DP[i][target] != -1) return DP[i][target];

    int notPick = 0 + f(i-1, arr, target);
    int pick = 1e9;
    if (target >= arr[i]) pick = 1 + f(i, arr, target-arr[i]);

    return DP[i][target] = min(pick, notPick);

}

int f3(vector<int>& arr, int target){
    int n = arr.size();
    vector<vector<int>> DP(n, vector<int> (target+1, 0));

    
    for (int i=0; i<=target; i++){
        if (i%arr[0] == 0){
            DP[0][i] = i/arr[0];
        }else{
            DP[0][i] = 1e9;
        }
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<target+1; j++){
            int notPick = 0 + DP[i-1][j];
            int pick = 1e9;
            if (target >= arr[i]) pick = 1 + DP[i][j-arr[i]];

            DP[i][j] = min(pick, notPick);
        }
    }

    return DP[n-1][target];
}

int f4(vector<int>& arr, int target){
    int n = arr.size();
    vector<int> prev(target+1, 0), curr(target+1, 0);

    
    for (int i=0; i<=target; i++){
        if (i%arr[0] == 0){
            prev[i] = i/arr[0];
        }else{
            prev[i] = 1e9;
        }
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<target+1; j++){
            int notPick = 0 + prev[j];
            int pick = 1e9;
            if (target >= arr[i]) pick = 1 + curr[j-arr[i]];

            curr[j] = min(pick, notPick);
        }
        prev = curr;
    }

    return prev[target];
}

int main(){

    vector<int> arr = {1, 2, 3};
    int target = 7;
    int n = arr.size();

    cout << "minimum coin denominations: " << f(n-1, arr, target) << endl;
    
    vector<vector<int>> DP(n, vector<int> (target+1, -1));
    cout << "minimum coin denominations MEMO: " << f2(n-1, arr, target, DP) << endl;
    cout << "minimum coin denominations TABU: " << f3(arr, target) << endl;
    cout << "minimum coin denominations TABU space optimized: " << f4(arr, target) << endl;


    return 0;
}