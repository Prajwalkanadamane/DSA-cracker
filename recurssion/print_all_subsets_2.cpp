
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void getSubsets(vector<int>& arr, vector<vector<int>>& allSubsets, vector<int>& ans, int i){

    if (i == arr.size()){
        // for (int val : ans){
        allSubsets.push_back(ans);
        return;
        // }
    } 
    ans.push_back(arr[i]);
    getSubsets(arr, allSubsets, ans, i+1);

    ans.pop_back();

    int idx = i+1;
    while (idx < arr.size() && arr[i] == arr[idx]){
        idx++;
    }
    getSubsets(arr, allSubsets, ans, idx);
}

vector<vector<int>> subSets(vector<int>& arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getSubsets(arr, allSubsets, ans, 0);
    return allSubsets;
}

int main(){
    vector<int> arr = {1,2,2,4};
    
    for (auto val : subSets(arr)){
        cout << "{";
        for (auto vl : val){
            cout << vl;
        }
        cout << "}";
        cout << endl;
    }
}