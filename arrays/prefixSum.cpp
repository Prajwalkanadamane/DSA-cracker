#include<iostream>
using namespace std;
#include<vector>

void prefixArrPrint(vector<int>& arr){
    
    for (int i=1; i<arr.size(); i++){
        arr[i] += arr[i-1];

    }
    cout << "After" << endl;
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Before" << endl;
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    } 
    cout << endl;

    prefixArrPrint(arr);
    return 0;
}