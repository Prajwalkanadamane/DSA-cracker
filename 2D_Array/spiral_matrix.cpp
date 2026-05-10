#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>>& mat){

    int top = 0, bottom = mat.size()-1;
    int left = 0, right = mat[0].size()-1;
    vector<int> ans;

    while (top <= bottom && left <= right){
        for (int j=left; j<=right; j++){
            ans.push_back(mat[top][j]);
        }
        top++;
        for (int j=top; j<=bottom; j++){
            ans.push_back(mat[j][right]);
        }
        right--;
        if(top <= bottom){
            for (int j=right; j>=left; j--){
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
        }
        if(left <= right){
            for (int j=bottom; j>=top; j--){
                ans.push_back(mat[j][left]);
            }
            left++;
        }

    }
    for (int elem: ans){
        
        cout << elem <<" ";
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    SpiralMatrix(matrix);
    return 0;
}