#include<bits/stdc++.h>
using namespace std;

int main(){
    // // approach 1 with TC: N*32
    // int ans = 0;
    // int nums[] = {5, 5, 5, 6, 4, 4, 4};
    // int n = 7;

    // for (int bitIdx=0; bitIdx<32; bitIdx++){
    //     int cnt = 0;
    //     for (int i=0; i<n; i++){
    //         if (nums[i] & 1 <<bitIdx){
    //             cnt++;
    //         }
    //     }
    //     if (cnt%3 == 1){
    //         ans = ans | (1 << bitIdx);
    //     }
    // }
    // cout << ans << endl;


    // approach 2 with TC: nlogN + n/3

    // int ans = 0;
    // vector<int> nums = {5, 5, 5, 2, 4, 4, 4};
    // sort(nums.begin(), nums.end());
    // int n = 7;
    
    // for (int i=1; i<n; i=i+3){
        //     if (nums[i-1] != nums[i]){
            //         cout << nums[i-1] << endl;
            //         return 0;
            //     }
            // }
            // cout << nums[n-1] << endl;


    // approach 2 with TC: O(n)
            
    vector<int> nums = {5, 5, 5, 2, 4, 4, 4};
    int ones = 0, twos = 0;

        for (int i=0; i<nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
    cout << ones << endl;
    return 0;
}