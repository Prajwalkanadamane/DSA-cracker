#include <iostream>
#include <vector>
using namespace std;

void getPermutations(vector<int>& arr, vector<vector<int>>& store,int idx){
    if (idx == arr.size()){
        store.push_back(arr);
        return;
    }

    for (int i=idx; i<arr.size(); i++){
        swap(arr[i], arr[idx]);
        getPermutations(arr, store, idx+1);

        swap(arr[i], arr[idx]);
    }
}

vector<vector<int>> permutations (vector<int>& arr){
    vector<vector<int>> store;

    getPermutations(arr,store, 0);

    return store;

}

int main(){
    vector<int> arr = {1,2,3};
    
    for(auto a : permutations(arr)){
        cout << "{";
        for (auto b : a){
            cout << b << "";
        }
        cout << "}";
        cout << endl;
    }
    return 0;

}