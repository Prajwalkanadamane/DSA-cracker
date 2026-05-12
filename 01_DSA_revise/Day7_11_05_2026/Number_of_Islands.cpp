#include<iostream>
#include<vector>
using namespace std;

void numberIslands(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){

    if (i < 0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] == '0' ){
        return;
    }

    vis[i][j] = true;

    numberIslands(i-1, j, vis, grid, n, m);
    numberIslands(i, j+1, vis, grid, n, m);
    numberIslands(i+1, j, vis, grid, n, m);
    numberIslands(i, j-1, vis, grid, n, m);

}

int main(){

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'}, 
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int Islands = 0;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, (vector<bool> (m, false)));

    for (int i=0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (grid[i][j] == '1' && !vis[i][j]){
                numberIslands(i, j, vis, grid, n, m);
                Islands++;
            }
        }
    }

    cout << "Number of Islands are: " << Islands << endl;


    return 0;
}