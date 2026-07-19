#include<iostream>
#include<vector>
#include<climits>
using namespace std;

long f(int idx, int buy, long *values, int n){

    if (idx == n) return 0;

    long profit = 0;

    if (buy){
        profit = max(-values[idx] + f(idx+1, 0, values, n),
                        0 + f(idx+1, 1, values, n));
    }else{
        profit = max(values[idx] + f(idx+1, 1, values, n),
                        0 + f(idx+1, 0, values, n));
    }

    return profit;

}

long f2(int idx, int buy, long *values, int n, vector<vector<long>>& DP){

    if (idx == n) return 0;

    if(DP[idx][buy] != -1) return DP[idx][buy];

    long profit = 0;

    if (buy){
        profit = max(-values[idx] + f2(idx+1, 0, values, n, DP),
                        0 + f2(idx+1, 1, values, n, DP));
    }else{
        profit = max(values[idx] + f2(idx+1, 1, values, n, DP),
                        0 + f2(idx+1, 0, values, n, DP));
    }

    return DP[idx][buy] = profit;

}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> DP(n+1, vector<long>(2, 0));

    DP[n][0] = DP[n][1] = 0;

    for (int i = n-1; i>=0; i--){
        for (int j=0; j<2; j++){
    
            long profit = 0;

            if (j){
                profit = max(-values[i] + DP[i+1][0],
                        0 + DP[i+1][1]);
            }else{
                profit = max(values[i] + DP[i+1][1],
                        0 + DP[i+1][0]);
            }        
            DP[i][j] = profit;
        }
    }

    return DP[0][1];
}

int main(){

    long values[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(values) / sizeof(values[0]);
    vector<vector<long>> DP(n, vector<long>(2, -1));

    cout << "Maximum Profit = " << f(0, 1, values, n) << endl;
    cout << "Maximum Profit MEMO = " << f2(0, 1, values, n, DP) << endl;
    cout << "Maximum Profit TABU = " << getMaximumProfit(values, n) << endl;


    return 0;
}