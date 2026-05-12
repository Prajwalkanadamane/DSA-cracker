#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>& prices){

    int maxP = 0;
    int minB = prices[0];

    for (int i=1; i<prices.size(); i++){
        maxP = max(maxP, prices[i]-minB);
        minB = min(minB, prices[i]);
    }

    return maxP;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int ans = solve(prices);
    cout << ans << endl;

    return 0;
}