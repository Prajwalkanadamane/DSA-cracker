#include<iostream>
#include<vector>
using namespace std;

int f(vector<int>& arr, int i, int target){

    if (target == 0) return 1;
    if (i == 0) return target == arr[i];

    int notP = f(arr, i-1, target);
    int Pick = 0;
    if (arr[i] <= target){
        Pick = f(arr, i-1, target - arr[i]);
    }

    return notP + Pick;

};

int f2(vector<int>& arr, int i, int target, vector<vector<int>>& DP){

    if (i == 0) return target == arr[i];
    if (target == 0) return 1;

    if (DP[i][target] != -1) return DP[i][target];

    int notP = f2(arr, i-1, target, DP);
    int Pick = 0;
    if (arr[i] <= target){
        Pick = f2(arr, i-1, target - arr[i], DP);
    }

    return DP[i][target] = notP + Pick;

};

int f3(vector<int> arr, int target){

    int n = arr.size();

    vector<vector<int>> DP(n, vector<int>(target+1, 0));

    for (int i=0; i<n; i++){
        DP[i][0] = 1;
    }

    if (arr[0] <= target) DP[0][arr[0]] = 1;

    for(int i=1; i<n; i++){
        for (int j = 0; j<=target; j++){
            int notP = DP[i-1][j];
            int pick = 0;
            if (j >= arr[i]) pick = DP[i-1][j-arr[i]];

            DP[i][j] = notP + pick;
        }
    }
    return DP[n-1][target];

}

int f4(vector<int> arr, int target){

    int n = arr.size();

    vector<int> prev(target+1, 0), curr(target+1);
    prev[0] = 1;


    if (arr[0] <= target) prev[arr[0]] = 1;

    for(int i=1; i<n; i++){
        for (int j = 0; j<=target; j++){
            int notP = prev[j];
            int pick = 0;
            if (j >= arr[i]) pick = prev[j-arr[i]];

            curr[j] = notP + pick;
        }
        prev = curr;
    }
    return prev[target];

}

int main(){

    vector<int> arr = {4, 2, 2 ,3};
    int n = arr.size();

    int target = 3;
    int ans = f(arr, n-1, target);
    
    cout << "There are " << ans << " number of subsequences = " << target << endl;
    
    vector<vector<int>> DP(n, vector<int>(target+1, -1));
    
    cout << "There are " << f2(arr, n-1, target, DP) << " number of subsequences using MEMO = " << target << endl;
    
    cout << "There are " << f3(arr, target) << " number of subsequences using TABU = " << target << endl;
    
    cout << "There are " << f4(arr, target) << " number of subsequences using TABU + SpaceOptimize = " << target << endl;


    return 0;
}