#include <iostream>
#include <vector>
using namespace std;

vector<int> ZigZagMatrix(vector<vector<int>>& mat){
    for (int i=0; i<mat.size(); i++){
        if(i%2 == 0){
            for (int j=0; j<mat[i].size(); j++){
                cout << mat[i][j] << " ";
            }
            cout << endl; 
        }
        else{
            for (int j=mat[i].size()-1; j>=0; j--){
                cout << mat[i][j] << " "; 
            }
            cout << endl; 
        }
    }
}


int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    ZigZagMatrix(matrix);
    return 0;
}