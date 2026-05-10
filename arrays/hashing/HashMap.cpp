#include<iostream>
#include<vector>
#include<map>
using namespace std;

void HashmapImp(vector<int>& arr, int query){

    map<int, int> maping;
    
    for (int i=0; i<arr.size(); i++){
        maping[arr[i]] += 1; 
    }

    cout << "The number " << query << " occurs " << maping[query] << " times!";

}

int main(){

    vector<int> arr = {7, 6, 7, 6, 7, 8, 0, 5, 6, 9};
    vector<int> Hash(arr.size(), 0);

    HashmapImp(arr, 7);

    return 0;
}