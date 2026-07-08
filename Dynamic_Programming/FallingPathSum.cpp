#include<iostream>
#include<vector>
using namespace std;

int Solve(int i, int j, vector<vector<int>>& matrix){


    if (j < 0 || j >= matrix[0].size()) return -1e8;
    if (i == 0) return matrix[i][j];


    int up = matrix[i][j] + Solve(i-1, j, matrix);
    int lDiagnol = matrix[i][j] + Solve(i-1, j-1, matrix);
    int rDiagnol = matrix[i][j] + Solve(i-1, j+1, matrix);

    return max(up, max(lDiagnol, rDiagnol));

}

int Solve2(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& DP){ // Memorization


    if (j < 0 || j >= matrix[0].size()) return -1e8;
    if (i == 0) return matrix[i][j];

    if (DP[i][j] != -1) return DP[i][j];

    int up = matrix[i][j] + Solve2(i-1, j, matrix,DP);
    int lDiagnol = matrix[i][j] + Solve2(i-1, j-1, matrix,DP);
    int rDiagnol = matrix[i][j] + Solve2(i-1, j+1, matrix, DP);

    return DP[i][j] = max(up, max(lDiagnol, rDiagnol));

}

int Solution(vector<vector<int>>& matrix){

    vector<vector<int>> DP(matrix.size(), vector<int> (matrix[0].size(), 0));

    for (int j = 0; j<matrix[0].size(); j++){
        DP[0][j] = matrix[0][j];
    }

    for (int i=1; i<matrix.size(); i++){
        for (int j=0; j<matrix[0].size(); j++){
            int up = matrix[i][j] + DP[i-1] [j];

            int lDiag = matrix[i][j];
            if (j>0) lDiag+= DP[i-1][j-1];
            else lDiag += -1e8;
            
            int rDiag = matrix[i][j];
            if (j<matrix[0].size()-1) rDiag+= DP[i-1][j+1];
            else rDiag += -1e8;

            DP[i][j] = max(up, max(lDiag, rDiag));
        }
    }
    int maxi = -1e8;
    for (int j=0; j<matrix[0].size(); j++){
        maxi = max(maxi, DP[matrix.size()-1][j]);
    }

    return maxi;

}

int main(){

    vector<vector<int>> matrix = {
        {1, 2, 10, 4}, 
        {100, 3, 2, 1}, 
        {1, 1, 20, 2}, 
        {1, 2, 2, 1}};

        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxi = -1e8;
        
        for (int cl=0; cl<n; cl++){
            int ans = Solve(m-1, cl, matrix);
            maxi = max(maxi, ans);
        }
        cout << "Maximum value path is: " << maxi << endl;
        
        maxi = -1e8;
        vector<vector<int>> DP(m, vector<int>(n, -1));
        for (int cl=0; cl<n; cl++){
            int ans = Solve2(m-1, cl, matrix, DP);
            maxi = max(maxi, ans);
        }
        cout << "Maximum value path using MEMO: " << maxi << endl;
        
        cout << "Maximum Value path using TABU: " << Solution(matrix) << endl;


    return 0;
}