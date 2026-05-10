#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedArray(vector<int>& A, int m, vector<int>& B, int n){
    int indx = m+n-1, i = m-1, j = n-1;
    while (i>=0 && j>=0){
        if (A[i] > B[j]){
            A[indx--] = A[i--];
        }
        else{
            A[indx--] = B[j--];
        }
    while (j>=0)
    {
        A[indx--] = B[j--];  
    } 

    }
    for (int num:A){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A = {1,2,3,0,0,0};
    int m = 6;
    vector<int> B = {2,5,6};
    int n = 3;

    mergeTwoSortedArray(A,m,B,n);
    return 0;
}