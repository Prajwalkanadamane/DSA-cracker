#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frogJump(int n, vector<int>& heights){ //recurssion based

    if (n == 0) return 0;

    int left = frogJump(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if (n>1){
        right = frogJump(n-2, heights) + abs(heights[n] - heights[n-2]);
    }

    return min(left, right);

}

int frogJump2(int n, vector<int>& heights, vector<int>& DP){

    if (n == 0) return 0;

    if (DP[n] != -1) return DP[n];

    int left = frogJump2(n-1, heights, DP) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if (n>1){
        right = frogJump2(n-2, heights, DP) + abs(heights[n] - heights[n-2]);
    }

    return DP[n] = min(left, right);

}

int frogJump3(int n, vector<int>& heights){

    vector<int> DP(n+1, 0);

    DP[0] = 0;

    for (int i=1; i<=n; i++){
        int fs = DP[i-1] + abs(heights[i]- heights[i-1]);
        int ss = INT_MAX;
        if (i>1) ss = DP[i-2] + abs(heights[i] - heights[i-2]);

        DP[i] = min(fs, ss);
    }

    return DP[n];
}

int main(){

    vector<int> heights = {30, 10, 60, 10, 60, 50};

    int n = 5;

    cout << "Minimum energy path using Recursion: " << frogJump(n, heights) << endl;

    vector<int> DP(n+1, -1);
    cout << "Minimum energy path using DP Memorization: " << frogJump2(n, heights, DP) << endl;

    cout << "Minimum energy path using DP Tabulation: " << frogJump3(n, heights) << endl;


    return 0;
}