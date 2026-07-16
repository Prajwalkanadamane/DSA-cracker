#include<iostream>
#include<vector>
using namespace std;

void f3(string& a, string& b){

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

    int len = DP[n][m];
    string S(len, '$');

    int i = n, j = m;
    int idx = len-1;

    while (i>0 && j>0){

        if (a[i-1] == b[j-1]){
            S[idx] = a[i-1];
            idx--;
            i--;
            j--;
        }
        else if (DP[i-1][j] >= DP[i][j-1]) i--;
        else j--;
    }
    for (int i=0; i<len; i++){
        cout << S[i] << " ";
    }
}

int main(){

    string a = "adebc";
    string b = "dcadb";

    f3(a, b);

    return 0;
}