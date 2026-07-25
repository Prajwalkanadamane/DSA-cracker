#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& cuts){

    if (i > j) return 0;

    int mini = 1e9;
    for (int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts) + f(k+1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}

int f2(int i, int j, vector<int>& cuts, vector<vector<int>>& DP){

    if (i > j) return 0;
    if (DP[i][j] != -1) return DP[i][j];

    int mini = 1e9;
    for (int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + f2(i, k-1, cuts, DP) + f2(k+1, j, cuts, DP);
        mini = min(mini, cost);
    }
    return DP[i][j] = mini;
}

int f3(vector<int>& cuts, int c, int n){

    vector<vector<int>> DP(c+2, vector<int> (c+2, 0)); //if c=4 it'll range from 0->3 c+1 will range from 0->4

    for (int i=c; i>=1; i--){
        for (int j=1; j<=c; j++){
            if (i>j) continue;
            int mini = 1e9;
            for (int k=i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1] + DP[i][k-1] + DP[k+1][j]; //when k == c it wants to access DP[k+1] so, the c+1 which is from ranging from 0->4 should be c+2
                mini = min(mini, cost);
            }
            DP[i][j] = mini;
        }
    }
    return DP[1][c];

}

int main(){

    vector<int> cuts = {3, 5, 1, 4};
    int n = 7;
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> DP(c+1, vector<int> (c+1, -1));
    cout << "minimum cost to cut a stick: " << f(1, c, cuts) << endl;
    cout << "minimum cost to cut a stick MEMO SLTN: " << f2(1, c, cuts, DP) << endl;
    cout << "minimum cost to cut a stick TABU SLTN: " << f3(cuts, c, n) << endl;

    return 0;
}