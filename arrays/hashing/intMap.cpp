#include<iostream>
#include<vector>
using namespace std;

void HashmapImp(vector<int>& arr, vector<int>& Hash, int query){
    
    for (int i=0; i<arr.size(); i++){
        Hash[arr[i]] += 1; 
    }

    cout << "The number " << query << " occurs " << Hash[query] << " times!";

}

int main(){

    vector<int> arr = {7, 6, 7, 6, 7, 8, 0, 5, 6, 9};
    vector<int> Hash(arr.size(), 0);

    HashmapImp(arr, Hash, 7);

    return 0;
}