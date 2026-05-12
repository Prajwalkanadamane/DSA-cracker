#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& nums){

    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for (int num : nums){
        if (num == 0){
            zeros++;
        }else if(num == 1){
            ones++;
        }else{
            twos++;
        }
    }

    int idx = 0;
    for (int i=0; i<zeros; i++){
        nums[idx] = 0;
        idx++;
    }

    for (int i=0; i<ones; i++){
        nums[idx] = 1;
        idx++;
    }

    for (int i=0; i<twos; i++){
        nums[idx] = 2;
        idx++;
    }

}

void dutchNationalFlag(vector<int>& nums){

    int mid = 0, high = nums.size()-1, low = 0;

    while(mid < high){
        if (nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++; low++;
        }else if (nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// The three-pointer technique (standard Dutch National Flag algorithm) partitions the array in one pass:

// Pointers: Use low (tracks 0s end), mid (current element), high (tracks 2s start).
// Partitioning:
// 0s: 0 to low-1
// 1s: low to mid-1
// 2s: high+1 to n-1
// Unknown: mid to high
// Traversal: Move mid through the array; swap based on value (0 with low, 2 with high, 1 skip).
// Efficiency: O(n) time, O(1) space, fully in-place and stable for equal elements.
// Advantage: Single pass, no extra memory; optimal for sorting 0,1,2.
// Edge Cases: Handles all 0s/1s/2s or mixed arrays correctly.

int main(){

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    for (int num: nums){
        cout << num << " ";
    }
    cout << endl;
    // solve(nums);
    dutchNationalFlag(nums);
    for (int num: nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

