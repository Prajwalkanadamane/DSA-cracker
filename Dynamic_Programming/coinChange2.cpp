#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i, int target, vector<int>& arr){

    
    if (i == 0){
        return target % arr[i] == 0;
    }
    int notpick = f(i-1, target, arr);
    int pick = 0;
    if (target >= arr[i]) pick = f(i, target-arr[i], arr);
    
    return pick + notpick;

}

int f2(int i, int target, vector<int>& arr, vector<vector<int>>& DP){
  
    if (i == 0){
        return target % arr[i] == 0;
    }

    if (DP[i][target] != -1) return DP[i][target];

    int notpick = f(i-1, target, arr);
    int pick = 0;
    if (target >= arr[i]) pick = f(i, target-arr[i], arr);
    
    return DP[i][target] = pick + notpick;

}

int f3(int target, vector<int>& arr){

    int n = arr.size();
    vector<vector<int>> DP(n, vector<int> (target+1, 0));

    for (int T=0; T<target+1; T++){
        if (T % arr[0] == 0) DP[0][T] = 1;
        // else DP[0][T] = 0; 
    }

    for (int i=1; i<n; i++){
        for(int j=0; j<target+1; j++){
        int notpick = DP[i-1][j];
        int pick = 0;
        if (j >= arr[i]) pick = DP[i][j-arr[i]];
    
        DP[i][j] = pick + notpick;       
        }
    }
    return DP[n-1][target];

}

int f4(int target, vector<int>& arr){

    int n = arr.size();
    vector<int> prev(target+1, 0), curr(target+1, 0);

    for (int T=0; T<target+1; T++){
        if (T % arr[0] == 0) prev[T] = 1;
        // else prev[T] = 0; 
    }

    for (int i=1; i<n; i++){
        for(int j=0; j<target+1; j++){
        int notpick = prev[j];
        int pick = 0;
        if (j >= arr[i]) pick = curr[j-arr[i]];
    
        curr[j] = pick + notpick;       
        }
        prev = curr;
    }
    return prev[target];

}

int main(){

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int target = 4;
    vector<vector<int>> DP(n, vector<int> (target+1, -1));

    cout << "There are total " << f(n-1, target, arr) << " subsets whose sum are equal to " << target << endl;
    cout << "There are total " << f2(n-1, target, arr, DP) << " subsets whose sum are equal to " << target << " using MEMO." << endl;
    cout << "There are total " << f3(target, arr) << " subsets whose sum are equal to " << target << " using TABU." << endl;
    cout << "There are total " << f4(target, arr) << " subsets whose sum are equal to " << target << " using space optimized." << endl;

    return 0;
}