#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;


int Solution(vector<vector<int>>& maze, int m, int n){ // recursion

    if (m>=0 && n>=0 && maze[m][n] == -1) return 0;

    if (m == 0 && n == 0) return 1;

    if (m<0 || n<0) return 0;

    int up = Solution(maze, m-1, n);
    int left = Solution(maze, m, n-1);

    return (up+left) % mod;

}

int Solution2(vector<vector<int>>& maze, int m, int n, vector<vector<int>>& DP){ // Memorization

    if (m>=0 && n>=0 && maze[m][n] == -1) return 0;

    if (m == 0 && n == 0) return 1;

    if (m<0 || n<0) return 0;

    if (DP[m][n] != -1) return DP[m][n];

    int up = Solution2(maze, m-1, n, DP);
    int left = Solution2(maze, m, n-1, DP);

    return DP[m][n] = (up+left) % mod;

}

int Solution3(vector<vector<int>>& maze, int m, int n){

    vector<vector<int>> DP(m+1, vector<int>(n+1,-1));

    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (maze[i][j] == -1) DP[i][j] = 0;
            else if (i == 0 && j == 0) DP[i][j] = 1;
            else{
                int up = 0, left = 0;
                if (i > 0) up = DP[i-1][j];
                if (j > 0) left = DP[i][j-1];

                DP[i][j] = (up + left) % mod;
            }
        }
    }
    return DP[m][n];


}

int main(){

    vector<vector<int>> maze = {{0,0,0}, {0,-1,0}, {0,0,0}};

    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> DP(m, vector<int>(n, -1));

    cout << "Unique paths are: " << Solution(maze, m-1, n-1) << endl;
    cout << "Unique paths are memorization: " << Solution2(maze, m-1, n-1, DP) << endl;
    cout << "Unique paths are Tabulation: " << Solution3(maze, m-1, n-1) << endl;

    return 0;
}