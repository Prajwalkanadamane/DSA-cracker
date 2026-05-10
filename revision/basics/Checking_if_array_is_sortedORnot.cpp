#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sorted(vector<int>& arr, int n){

    if (n == 1 || n == 0){
        cout << " array is sorted." << endl;
    }

    if (arr[n-1] < arr[n-2]){
        cout << "array isn't sorted." << endl;
    }

    sorted(arr, n-1);
}
    

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    sorted(arr, arr.size());
    return 0;  
}