#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int f3(string& a, string& b){

    int n = a.size();
    int m = b.size();
    vector<vector<int>> DP(n+1, vector<int>(m+1, 0));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i-1] == b[j-1]){
                DP[i][j] = 1 + DP[i-1][j-1];
            }else
            DP[i][j] = max (DP[i-1][j], DP[i][j-1]);
        }
    }
    return DP[n][m];
}


int main(){

    string a = "adebc";
    string b = "dcadb";

    int n = a.size();
    int m = b.size();

    int ans = f3 (a, b);

    cout << "Minimum Insertions/Deletions to Convert String A to String B: " << (n-ans) + (m-ans) << endl;

    return 0;
}