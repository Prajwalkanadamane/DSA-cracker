#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i, int knapSackW, vector<int>& values, vector<int>& weights){

    if (i == 0) {
        if (weights[0] <= knapSackW) return values[0];
        return 0;
    }

    int notSteal = 0 + f(i-1, knapSackW, values, weights);
    int steal = -1e8;

    if (weights[i] <= knapSackW) steal = values[i] + f(i-1, knapSackW-weights[i], values, weights);

    return max(notSteal, steal);

}

int f2(int i, int knapSackW, vector<int>& values, vector<int>& weights, vector<vector<int>>& DP){

    if (i == 0) {
        if (weights[0] <= knapSackW) return values[0];
        return 0;
    }

    if (DP[i][knapSackW] != -1) return DP[i][knapSackW];

    int notSteal = 0 + f2(i-1, knapSackW, values, weights, DP);
    int steal = -1e8;

    if (weights[i] <= knapSackW) steal = values[i] + f2(i-1, knapSackW-weights[i], values, weights, DP);

    return DP[i][knapSackW] = max(notSteal, steal);

}

int f3(int knapSackW, vector<int>& values, vector<int>& weights){
    vector<vector<int>> DP(weights.size(), vector<int> (knapSackW+1, 0));

    for (int i=0; i<=knapSackW; i++){
        if (i >= weights[0]) DP[0][i] = values[0];
    }
    

    for (int i=1; i<weights.size(); i++){
        for (int j=0; j<=knapSackW+1; j++){
            int notSteal = 0 + DP[i-1][j];
            int steal = -1e8;

            if (weights[i] <= knapSackW) steal = values[i] + DP[i-1][j-weights[i]];

            DP[i][j] = max(notSteal, steal);
        }
    }
    return DP[weights.size()-1][knapSackW];

}

int f4(int knapSackW, vector<int>& values, vector<int>& weights){
    vector<int> prev(knapSackW+1, 0), curr(knapSackW+1, 0);

    for (int i=0; i<=knapSackW; i++){
        if (i >= weights[0]) prev[i] = values[0];
    }
    

    for (int i=1; i<weights.size(); i++){
        for (int j=0; j<=knapSackW+1; j++){
            int notSteal = 0 + prev[j];
            int steal = -1e8;

            if (weights[i] <= knapSackW) steal = values[i] + prev[j-weights[i]];

            curr[j] = max(notSteal, steal);
        }
        prev = curr;
    }
    return prev[knapSackW];

}



int main(){

    vector<int> values = {3000, 2000, 1500};
    vector<int> weights = {4, 3, 1};
    int KnapsackW = 4;
    int n = weights.size();
    vector<vector<int>> DP(n, vector<int> (KnapsackW+1, -1));

    cout << "ans: " << f(n-1, KnapsackW, values, weights) << endl;
    cout << "ans MEMO: " << f2(n-1, KnapsackW, values, weights, DP) << endl;
    cout << "ans TABU: " << f3(KnapsackW, values, weights) << endl;
    cout << "ans TABU space optimized: " << f4(KnapsackW, values, weights) << endl;

    return 0;
}
