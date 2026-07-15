#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i, int rLnth, vector<int>& prices){

    if (i==0){
        return rLnth*prices[i];
    }

    int Ncut = 0 + f(i-1, rLnth, prices);
    int cut = -1e9;
    if (rLnth >= i+1){
        cut = prices[i] + f(i, rLnth-(i+1), prices);
    }

    return max(Ncut, cut);

}


int f2(int i, int rLnth, vector<int>& prices, vector<vector<int>>& DP){

    if (i==0){
        return rLnth*prices[i];
    }

    if (DP[i][rLnth] != -1) return DP[i][rLnth];

    int Ncut = 0 + f2(i-1, rLnth, prices, DP);
    int cut = -1e9;
    if (rLnth >= i+1){
        cut = prices[i] + f2(i, rLnth-(i+1), prices, DP);
    }

    return DP[i][rLnth] = max(Ncut, cut);

}

int f3(int rLnth, vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> DP(n, vector<int>(rLnth+1, 0));

    for (int i=0; i<=rLnth; i++){
        DP[0][i] = i*prices[0];
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<=rLnth; j++){
            int Ncut = 0 + DP[i-1][j];
            int cut = -1e9;
            if (j >= i+1){
                cut = prices[i] + DP[i][j-(i+1)];
            }
            DP[i][j] = max(Ncut, cut);
        }
    }
    return DP[n-1][rLnth]; 

}

int main(){

    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int rLnth = 8;
    int n = prices.size();

    cout << "ans: " <<  f(n-1, rLnth, prices) << endl;
    
    vector<vector<int>> DP(n, vector<int>(rLnth+1, -1));
    cout << "ans2: " <<  f2(n-1, rLnth, prices, DP) << endl;
    cout << "ans3: " <<  f3(rLnth, prices) << endl;


    return 0;
}