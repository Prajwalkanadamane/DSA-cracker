#include<iostream>
#include<vector>
using namespace std;

int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& matrix){

    if (j1 < 0 || j2 < 0 || j1 >=  c || j2 >= c) return -1e8;

    if (i == r-1){
        if (j1 == j2) return matrix[i][j1];
        else return matrix[i][j1] + matrix[i][j2];
    }

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= +1; dj1++){
        for (int dj2 = -1; dj2 <= +1; dj2++){
            int value = 0;
            if (j1 == j2) value = matrix[i][j1];
            else value = matrix[i][j1] + matrix[i][j2];
            value += f(i+1, j1+dj1, j2+dj2, r, c, matrix);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int f2(int i, int j1, int j2, int r, int c, vector<vector<int>>& matrix, vector<vector<vector<int>>>& DP){

    if (j1 < 0 || j2 < 0 || j1 >=  c || j2 >= c) return -1e8;

    if (i == r-1){
        if (j1 == j2) return matrix[i][j1];
        else return matrix[i][j1] + matrix[i][j2];
    }

    if (DP[i][j1][j2] != -1) return DP[i][j1][j2];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= +1; dj1++){
        for (int dj2 = -1; dj2 <= +1; dj2++){
            int value = 0;
            if (j1 == j2) value = matrix[i][j1];
            else value = matrix[i][j1] + matrix[i][j2];
            value += f2(i+1, j1+dj1, j2+dj2, r, c, matrix, DP);
            maxi = max(maxi, value);
        }
    }
    return DP[i][j1][j2] = maxi;
}

int main(){

    vector<vector<int>> matrix = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};

    int r = matrix.size();
    int c = matrix[0].size();

    cout << "Cherry pick up answer: " << f(0, 0, c-1, r, c, matrix) <<  endl;
    
    vector<vector<vector<int>>> DP(r, vector<vector<int>>(c, vector<int>(c, -1)));
    cout << "Cherry pick up answer MEMO: " << f2(0, 0, c-1, r, c, matrix, DP) <<  endl;

    return 0;
}