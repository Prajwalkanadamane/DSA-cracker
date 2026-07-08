#include<iostream>
#include<vector>
using namespace std;

int Solution(int i, int j, int n, vector<vector<int>>& triangle){ //recursion

    if (i == n-1) return triangle[i][j];

    int down = triangle[i][j] + Solution(i+1, j, n, triangle);
    int diagnol = triangle[i][j] + Solution(i+1, j+1, n, triangle);

    return min(down, diagnol);

}



int Solution2(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& DP){ //Memorization

    if (i == n-1) return triangle[i][j];

    int down = triangle[i][j] + Solution(i+1, j, n, triangle);
    int diagnol = triangle[i][j] + Solution(i+1, j+1, n, triangle);

    return min(down, diagnol);

}

int Solution3(int i, int j, int n, vector<vector<int>>& triangle){

    vector<vector<int>> DP(n, vector<int>(n, 0));

    for (int i=0; i<n; i++){
        DP[n-1][i] = triangle[n-1][i];
    }

    for (int i=n-2; i>=0; i--){
        for (int j=i; j>=0; j--){
            int down = triangle[i][j] + DP[i+1][j];
            int diagnol = triangle[i][j] + DP[i+1][j+1];
            DP[i][j] = min(down,diagnol);
        }
    }

    return DP[0][0];

}




int main(){

    vector<vector<int>> triangle = {{1}, {2,3}, {4,5,6}, {7,8,9,10}};
    vector<vector<int>> triangle2 = {{2},{3,4},{6,5,7},{4,1,8,3}};

    int n = triangle.size();
    int i = 0, j = 0;

    cout << "The minimum path: " << Solution(i, j, n, triangle) << endl;
    cout << "The minimum path: " << Solution(i, j, n, triangle2) << endl;
    
    vector<vector<int>> DP(n, vector<int>(n, -1));
    cout << "The minimum path using MEMO: " << Solution2(i, j, n, triangle, DP) << endl;
    cout << "The minimum path using MEMO: " << Solution2(i, j, n, triangle2, DP) << endl;
    
    cout << "The minimum path using TABU: " << Solution3(i, j, n, triangle) << endl;
    cout << "The minimum path using TABU: " << Solution3(i, j, n, triangle2) << endl;

    return 0;
}