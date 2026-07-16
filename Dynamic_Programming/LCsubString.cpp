#include<iostream>
#include<vector>
#include<string>
using namespace std;

int ans = 0;

int f(int i, int j, string& a, string& b){

    if (i < 0 || j < 0){
        return 0;
    }
    int curr = 0;

    if (a[i] == b[j]){
        curr = 1 + f(i-1, j-1, a, b);
        ans = max(ans, curr);
    }
    f(i-1, j, a, b);
    f(i, j-1, a, b);

    return curr;

}

int f3(string& a, string& b){

    int n = a.size();
    int m = b.size();
    vector<vector<int>> DP(n+1, vector<int>(m+1, 0));

    int ans2 = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i-1] == b[j-1]){
                DP[i][j] = 1 + DP[i-1][j-1];
                ans2 = max(ans, DP[i][j]);
            }else
            DP[i][j] = 0;
        }
    }
    return ans2;
}

int main(){

    string a = "adebc";
    string b = "dcadb";

    int n = a.size();
    int m = b.size();

    f (n-1, m-1, a, b);
    cout << "Longest common substring is of lenght: " << f3 (a, b) << endl;

    cout << "Longest common substring is of lenght: " << ans << endl;


    return 0;
}