#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> TwoSum(vector<int>& arr, int tar){
    unordered_map<int,int> mp;
    vector<vector<int>> ans;

    for (int i=0; i<arr.size(); i++){
        int complement = tar - arr[i];

        if (mp.find(complement) != mp.end()){
            ans.push_back({mp[complement], i});
        }
        mp[arr[i]] = i;
    }
    return ans;

}

int main() {
    vector<int> nums = {5,4,2,3,11,7,15};
    int target = 9;

    vector<vector<int>> result = TwoSum(nums, target);

    for (auto& pair : result) {
        cout << "Indices: [" << pair[0] << ", " << pair[1] << "]\n";
    }
    return 0;
}