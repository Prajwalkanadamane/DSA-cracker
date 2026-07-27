#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int fee)
{

    vector<vector<int>> DP(n+1, vector<int>(2, 0));

    for (int idx = n-1; idx >= 0; idx--){
        for (int buy=0; buy < 2; buy++){
            
            int profit = 0;

            if (buy){
                profit = max( -prices[idx] - fee + DP[idx+1][0],
                                         0 + DP[idx+1][1]);
            }else{
                profit = max( prices[idx] + DP[idx+1][1],
                                        0 + DP[idx+1][0]);
            }
            DP[idx][buy] = profit;
        }
    }
    return DP[0][1];
}

int main(){
    vector<int> prices = {1, 3, 5, 6};
    int n = 4;
    int k = 2;
    cout << "ans with the transaction fee: " << maximumProfit(prices, n, k) << endl;

    return 0;
}