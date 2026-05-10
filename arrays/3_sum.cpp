//Brute force approach

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threesum (vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k = j+1; k<n; k++){
                if (nums[i]+nums[j]+nums[k] == 0){
                    vector<int>trip = {nums[i],nums[j],nums[k]};
                    sort(trip.begin(),trip.end());
                    if (s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;


}


// Function to print the 2D vector properly
void printResult(const vector<vector<int>>& result) {
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, 3};

    vector<vector<int>> result = threesum(nums);

    cout << "Triplets that sum to 0:\n";
    printResult(result);

    return 0;
}

 /*Optimized version O(n^2)*/
// vector<vector<int>> threeSum(vector<int>& nums){
    
//     set<vector<int>> ans;
    
//     for (int i=0; i<nums.size(); i++){
//         int first = nums[i];
//         set<int> S;
        
//         for (int j=i+1; j<nums.size(); j++){
//             int second = nums[j];
//             int third = first + second;
//             third = -third;
            
//             if (S.find(third) != S.end()){
//                 vector<int> triplet = {first, second, third};
//                 sort(triplet.begin(), triplet.end());
//                 ans.insert(triplet);
//             }
//             S.insert(second);
//         }
//     }
//     vector<vector<int>> Fans(ans.begin(), ans.end());
//     return Fans;
// }


// int main(){
//     vector<int> arr = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> threeSumm = threeSum(arr);
//     for (auto outerB=0; outerB< threeSumm.size(); outerB++){
//         cout << "[";
//         for (auto innerB=0; innerB<threeSumm[0].size(); innerB++){
//             cout << threeSumm[outerB][innerB] << " ";
//         }
//         cout << "]";
//         cout <<endl;
//     }
//     cout <<endl;
//     return 0;
// }