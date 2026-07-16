#include<iostream>
#include<vector>
#include<string>
using namespace std;

int f(int i, int j, string& a, string& b){

    if (i < 0 || j < 0){
        return 0;
    }

    if (a[i] == b[j]){
        return 1 + f(i-1, j-1, a, b);
    }
    return max (f(i-1, j, a, b), f(i, j-1, a, b));

}

int f2(int i, int j, string& a, string& b, vector<vector<int>>& DP){

    if (i < 0 || j < 0){
        return 0;
    }
    if (DP[i][j] != -1) return DP[i][j];

    if (a[i] == b[j]){
        return DP[i][j] = 1 + f2(i-1, j-1, a, b, DP);
    }
    int choosei = f2(i-1, j, a, b, DP);
    int choosej = f2(i, j-1, a, b, DP);
    return DP[i][j] = max(choosei, choosej);

}

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
    vector<vector<int>> DP(n, vector<int>(m, -1));

    cout << "Longest common substring is of lenght: " << f (n-1, m-1, a, b) << endl;
    cout << "Longest common substring is of lenght: " << f2 (n-1, m-1, a, b, DP)<< endl;
    cout << "Longest common substring is of lenght: " << f3 (a, b)<< endl;

    return 0;
}

// string f(int i, int j, string &a, string &b) {

//     if (i < 0 || j < 0)
//         return "";

//     if (a[i] == b[j])
//         return f(i - 1, j - 1, a, b) + a[i];

//     string s1 = f(i - 1, j, a, b);
//     string s2 = f(i, j - 1, a, b);

//     return (s1.size() > s2.size()) ? s1 : s2;
// }