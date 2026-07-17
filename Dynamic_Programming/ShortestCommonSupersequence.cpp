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

    string S = "";

    int i = n, j = m;

    while (i>0 && j>0){

        if (a[i-1] == b[j-1]){
            S += a[i-1];
            i--;
            j--;
        }
        else if (DP[i-1][j] >= DP[i][j-1]) S +=a[i-1], i--;
        
        else S +=b[j-1], j--;
    }

    while(i>0) S += a[i-1], i--;
    while(j>0) S += b[j-1], j--;

    for (int i=0; i<S.size(); i++){
        cout << S[i] << " ";
    }
}

int main(){

    string a = "adebc";
    string b = "dcadb";

    f3(a, b);

    return 0;
}