#include<iostream>
#include<vector>
using namespace std;

int Solution(int i, int j){ // Recursion based approach

    if (i == 0 && j == 0) return 1;

    if (i < 0 || j < 0) return 0;

    int up = Solution(i-1, j);
    int left = Solution(i, j-1);

    return up+left;

}

int Solution2(int i, int j, vector<vector<int>>& DP){

    if (i == 0 && j == 0) return 1;

    if (i < 0 || j < 0) return 0;

    if (DP[i][j] != -1) return DP[i][j];

    int up = Solution2(i-1, j, DP);
    int left = Solution2(i, j-1, DP);

    return DP[i][j] = up+left;

}

int Solution3(int i, int j){

    vector<vector<int>> DP(i+1, vector<int>(j+1, -1));

    for (int m=0; m<=i; m++){
        for (int n=0; n<=j; n++){
            if (m == 0 && n == 0) DP[m][n] = 1;
            else{

                int up = 0, left = 0;
    
                if (m > 0) up = DP[m-1][n];
                if (n > 0) left = DP[m][n-1];
    
                DP[m][n] = up + left;
            }

        }
    }
    return DP[i][j];

}

int main(){

    vector<vector<int>> grid = {{2,2}, {1,1}};

    int m = grid.size();
    int n = grid[0].size();

    int ans = Solution(m-1, n-1);
    cout << "Number of possible paths: " <<  ans << endl;

    vector<vector<int>> DP(m, vector<int>(n, -1));
    int ans2 = Solution2(m-1, n-1, DP);
    cout << "Number of possible paths using memorization: " << ans2 << endl;
    
    int ans3 = Solution3(m-1, n-1);
    cout << "Number of possible paths using Tabulation: " << ans3 << endl;


    return 0;
}