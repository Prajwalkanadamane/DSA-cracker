#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i, int knapSackW, vector<int>& values, vector<int>& weights){

    if (i == 0) {
        return ((int)(knapSackW/weights[0])) * values[0];
    }

    int notSteal = 0 + f(i-1, knapSackW, values, weights);
    int steal = -1e8;

    if (weights[i] <= knapSackW) steal = values[i] + f(i, knapSackW-weights[i], values, weights);

    return max(notSteal, steal);

}

int f2(int i, int knapSackW, vector<int>& values, vector<int>& weights, vector<vector<int>>& DP){

    if (i == 0) {
        return ((int)(knapSackW/weights[0])) * values[0];

    }

    if (DP[i][knapSackW] != -1) return DP[i][knapSackW];

    int notSteal = 0 + f2(i-1, knapSackW, values, weights, DP);
    int steal = -1e8;

    if (weights[i] <= knapSackW) steal = values[i] + f2(i, knapSackW-weights[i], values, weights, DP);

    return DP[i][knapSackW] = max(notSteal, steal);

}

int f3(int knapSackW, vector<int>& values, vector<int>& weights){
    vector<vector<int>> DP(weights.size(), vector<int> (knapSackW+1, 0));

    for (int i=weights[0]; i<=knapSackW; i++){
        DP[0][i] = ((int)(i/weights[0])) * values[0];
    }
    

    for (int i=1; i<weights.size(); i++){
        for (int j=0; j<=knapSackW; j++){
            int notSteal = 0 + DP[i-1][j];
            int steal = 0;

            if (weights[i] <= j) steal = values[i] + DP[i][j-weights[i]];

            DP[i][j] = max(notSteal, steal);
        }
    }
    return DP[weights.size()-1][knapSackW];

}

int f4(int knapSackW, vector<int>& values, vector<int>& weights){
    vector<int> prev(knapSackW+1, 0), curr(knapSackW+1, 0);

    for (int i=weights[0]; i<=knapSackW; i++){
        prev[i] = ((int)(i/weights[0])) * values[0];
    }
    

    for (int i=1; i<weights.size(); i++){
        for (int j=0; j<=knapSackW; j++){
            int notSteal = 0 + prev[j];
            int steal = 0;

            if (weights[i] <= j) steal = values[i] + curr[j-weights[i]];

            curr[j] = max(notSteal, steal);
        }
        prev = curr;
    }
    return prev[knapSackW];

}



int main(){

    vector<int> values = {10, 40, 50};
    vector<int> weights = {1, 3, 4};
    int W = 20;

    values = {3, 7, 12};
    weights = {2, 5, 7};
    W = 20;

    values = {10, 30, 20};
    weights = {5, 10, 15};
    W = 100;
    
    int n = weights.size();
    vector<vector<int>> DP(n, vector<int> (W+1, -1));

    cout << "ans: " << f(n-1, W, values, weights) << endl;
    cout << "ans MEMO: " << f2(n-1, W, values, weights, DP) << endl;
    cout << "ans TABU: " << f3(W, values, weights) << endl;
    cout << "ans TABU space optimized: " << f4(W, values, weights) << endl;

    return 0;
}
