// creating a 2D array
// #include <iostream>
// using namespace std;

// int main(){
//     int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
//     cout << matrix [0] [2] << endl;
//     matrix [0][2] = 18;
//     cout << matrix [0] [2] << endl;
//     return 0;
// }

// looping through an array
// #include <iostream>
// using namespace std;

// int main(){
//     int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    
//     int row = 3;
//     int column = 3;

//     for (int i=0; i<row; i++){
//         for (int j=0; j<column; j++){
//             cout << matrix [i] [j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// linearSearch
// #include <iostream>
// using namespace std;

// bool linearSearch(int matrix [] [3], int row, int column, int key, int &foundRow, int &foundColumn){
//     for (int i=0; i<row; i++){
//         for(int j=0; j<column; j++){
//             if (matrix [i] [j] == key ){
//                 foundRow = i;
//                 foundColumn = j;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    
//     int row = 3;
//     int column = 3;
//     int key = -89546972;

//     int foundRow = -1, foundcolumn = -1;

//     if (linearSearch(matrix, row, column, key, foundRow, foundcolumn)){
//         cout << "key " << key << " is found at row: " << foundRow <<" & column: " << foundcolumn;
//     }else{
//         cout << "key " << key << " not found.";
//     }
//     return 0;
// }

// Maximum column sum
// #include <iostream>
// #include <climits>
// using namespace std;

// int maxColumnSum(int matrix [] [3], int row, int column){
//     int maxColumnSum = INT_MIN;

//     for (int j=0; j<column; j++){
//         int ColumnMaxJ = 0;
//             for (int i=0; i<row; i++){
//             ColumnMaxJ += matrix [i] [j];
//             }
//         maxColumnSum = max (maxColumnSum, ColumnMaxJ);
//     }
//     return maxColumnSum;
// }

// int main(){
//     int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    
//     int row = 3;
//     int column = 3;

//     cout << "Maximum Row sum is: " << maxColumnSum(matrix, row,column);
//     return 0;
// }

// Maximum row sum
// #include <iostream>
// #include <climits>
// using namespace std;

// int maxRowSum(int matrix [] [3], int row, int column){
//     int maxRowSum = INT_MIN;

//     for (int i=0; i<row; i++){
//         int rowMaxI = 0;
//         for (int j=0; j<column; j++){
//             rowMaxI += matrix [i] [j];
//         }
//         maxRowSum = max (maxRowSum, rowMaxI);
//     }
//     return maxRowSum;
// }

// int main(){
//     int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    
//     int row = 3;
//     int column = 3;

//     cout << "Maximum Row sum is: " << maxRowSum(matrix, row,column);
//     return 0;
// }

#include <iostream>
using namespace std;

int diagnolMatrix(int matrix [] [3], int n){
    int Diagnolsum = 0;
//     for (int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if (i == j){
//                 Diagnolsum += matrix[i] [j]; 
//             }else if (j == n-1-i)
//             {
//                 Diagnolsum += matrix[i][j];
//             }
            
//         }
//     }
//     return Diagnolsum;
// }

// // or 
    for (int i=0; i<n; i++){
        Diagnolsum+= matrix[i] [i];

        if (i != n-1-1){
            Diagnolsum += matrix[i][n-1-i];
        }
    }
    return Diagnolsum; 
}

int main(){
    int matrix [3] [3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    
    int n = 3;

    cout << "Sum of diagonol elements of matrix: " << diagnolMatrix(matrix,n);

    return 0;
}
