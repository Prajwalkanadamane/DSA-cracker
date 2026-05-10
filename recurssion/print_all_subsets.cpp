// #include <iostream>
// #include <vector>
// using namespace std;

// void printSubset(vector<int> arr, vector<int> ans, int i){

//     if (i == arr.size()){
//         for (auto val : ans){
//             cout << val << " ";
//         }
//         cout << endl;
//         return;
//     } 

//     ans.push_back(arr[i]);
//     printSubset(arr, ans, i+1);

//     ans.pop_back();
//     printSubset(arr, ans, i+1);
// }


// int main(){
//     vector<int> arr = {1,2,3};
//     vector<int> ans;

//     printSubset(arr, ans, 0);
//     return 0;
// }

// leetcode approach

#include <iostream>
using namespace std;
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
    getSubsets(arr, allSubsets, ans, i+1);
}

vector<vector<int>> subSets(vector<int>& arr){
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getSubsets(arr, allSubsets, ans, 0);
    return allSubsets;
}

int main(){
    vector<int> arr = {1,2,3,4};
    
    for (auto val : subSets(arr)){
        cout << "{";
        for (auto vl : val){
            cout << vl;
        }
        cout << "}";
        cout << endl;
    }
}