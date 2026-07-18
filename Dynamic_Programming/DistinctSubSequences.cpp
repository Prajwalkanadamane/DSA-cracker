#include<iostream>
#include<vector>
#include<string>
using namespace std;

    int f(int i, int j, string& a, string& b, vector<vector<int>>& DP){

        if (j<0) return 1;
        if (i<0) return 0;

        if (DP[i][j] != -1) return DP[i][j];

        if (a[i] == b[j]) {
            return DP[i][j] = f(i-1, j-1, a, b, DP) + f(i-1, j, a, b, DP);
        }
        return DP[i][j] = f(i-1, j, a, b, DP);

    }

    int f2(string& a, string& b){

        int n = a.size();
        int m = b.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);
        prev[0] = curr[0] = 1;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (a[i-1] == b[j-1]) {
                    curr[j] = prev[j-1]+ prev[j];
                }else curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }

int main(){

    string a = "babgbag";
    string b = "bag";

    int n = a.size();
    int m = b.size();
    vector<vector<int>> DP(n, vector<int>(m, -1));

    cout << "ans: " << f(n-1, m-1, a, b, DP) << endl;
    cout << "ans: " << f2(a, b) << endl;

    return 0;
}