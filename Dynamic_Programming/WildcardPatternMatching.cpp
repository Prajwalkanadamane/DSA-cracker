#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool wildcardMatching(string a, string b){

   int n = a.size();
   int m = b.size();
   vector<vector<bool>> DP(n+1, vector<bool>(m+1, false));

   DP[0][0] = true;

   for (int i=1; i<=m; i++){
      DP[0][i] = false;
   }

   for (int i=1; i<=n; i++){
      bool flag = true;
      for (int y=1; y<=i; y++){
         if (a[y-1] != '*') flag = false;
         break;
      }
      DP[i][0] = flag;
   }

   for (int i=1; i<=n; i++){
      for (int j=1; j<=m; j++){

         if (a[i-1] == b[j-1] || a[i-1] == '?'){
            DP[i][j] = DP[i-1][j-1];
         }

         if (a[i-1] == '*'){
            DP[i][j] = DP[i-1][j] || DP[i][j-1];
         }
      }
   }
   

   return DP[n][m];
}

int main(){

    string a = "*ay";
    string b = "ray";

    cout << wildcardMatching(a, b) << endl;

}