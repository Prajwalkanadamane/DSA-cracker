#include<vector>
#include<iostream>
using namespace std;

int f(int idx, vector<int>& prices, int buy, int cap, int n){

    if (idx == n) return 0;
    if (cap <= 0) return 0;


    int profit = 0;
    if (buy){
        profit = max( -prices[idx] + f(idx+1, prices, 0, cap, n),
                      0 + f(idx+1, prices, 1, cap, n));
    }else{
        profit = max( prices[idx] + f(idx+1, prices, 1, cap-1, n),
                      0 + f(idx+1, prices, 0, cap, n));
    }

    return profit;

}

int f2(int idx, vector<int>& prices, int buy, int cap, int n, vector<vector<vector<int>>>& DP){

    if (idx == n) return 0;
    if (cap <= 0) return 0;

    if (DP[idx][buy][cap] != -1) return DP[idx][buy][cap];

    int profit = 0;
    if (buy){
        profit = max( -prices[idx] + f2(idx+1, prices, 0, cap, n, DP),
                      0 + f2(idx+1, prices, 1, cap, n, DP));
    }else{
        profit = max( prices[idx] + f2(idx+1, prices, 1, cap-1, n, DP),
                      0 + f2(idx+1, prices, 0, cap, n, DP));
    }

    return DP[idx][buy][cap] = profit;

}

int maxProfit(vector<int>& prices){

    int idx = 0;
    int buy = 1;
    int cap = 2;
    int n = prices.size();
    vector<vector<vector<int>>> DP
    (n, vector<vector<int>>(2, vector<int> (3, -1)));

    return f2(idx, prices, buy, cap, n, DP);
    // return f(idx, prices, buy, cap, n);
}

int main(){

    vector<int> prices = {3, 3, 5, 0, 3, 1, 4};
    cout << "Output: " << maxProfit(prices) << endl;

    return 0;
}