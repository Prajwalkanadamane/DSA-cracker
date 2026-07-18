#include<iostream>
#include<vector>
#include<string>
using namespace std;

int f(int i, int j, string& a, string& b){

    if (i<0) return j+1;
    if (j<0) return i+1;

    if (a[i] == b[j]){
        return 0 + f(i-1, j-1, a, b);
    }
        

    int insrt = 1 + f(i, j-1, a, b);
    int delt = 1 + f(i-1, j, a, b);
    int replce = 1 + f(i-1, j-1, a, b);

    return min(insrt, min(delt, replce));

}

int f2(int i, int j, string& a, string& b, vector<vector<int>>& DP){

    if (i<0) return j+1;
    if (j<0) return i+1;

    if (DP[i][j] != -1) return DP[i][j];

    if (a[i] == b[j]){
        return DP[i][j] = 0 + f2(i-1, j-1, a, b, DP);
    }
                    

    int insrt = 1 + f2(i, j-1, a, b, DP);
    int delt = 1 + f2(i-1, j, a, b, DP);
    int replce = 1 + f2(i-1, j-1, a, b, DP);

    return DP[i][j] =  min(insrt, min(delt, replce));

}

    int minDistance(string a, string b) {

        int n = a.size();
        int m = b.size();

        vector<vector<int>> DP(n+1, vector<int>(m+1, 0));

        for (int i=0; i<=n; i++){
            DP[i][0] = i;
        }
        for (int j=0; j<=m; j++){
            DP[0][j] = j;
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (a[i-1] == b[j-1]){
                    DP[i][j] = 0 + DP[i-1][j-1];
                }else{
                    int insrt = 1 + DP[i][j-1];
                    int delt = 1 + DP[i-1][j];
                    int replce = 1 + DP[i-1][j-1];

                    DP[i][j] =  min(insrt, min(delt, replce));                
                }
            }
        }
        return DP[n][m];
   
    }

int main(){

    string a = "horse";
    string b = "ros";

    int n = a.size();
    int m = b.size();
    vector<vector<int>> DP(n, vector<int>(m, -1));

    cout << "ans: " << f(n-1, m-1, a, b) << endl;
    cout << "ans2: " << f2(n-1, m-1, a, b, DP) << endl;
    cout << "ans3: " << minDistance(a, b) << endl;
    // cout << "ans: " << f2(a, b) << endl;

    return 0;
}