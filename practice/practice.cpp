#include <iostream>
#include <vector>
using namespace std;

int sortt(vector<int> &arr){
    int n = arr.size();
    int i = 0;
    int j = n-1;

    while (i<j){
        if (arr[i] >= arr[j]){
            swap(arr[i], arr[j]);
            j--;
        }else{
            i++;
        }
    }
}



int main(){
    vector<int> arr = {2,0,1};
    for (auto x : arr){
        cout << x << " ";
    }
    cout << endl;
    sortt(arr);
    for (auto x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
//0,0,2,1,1,2
