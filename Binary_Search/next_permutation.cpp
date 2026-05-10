#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    int pivot = -1;

    for (int i=n-1; i>=0; i--){
        if (nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }
    if (pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i =n-1; i>pivot; i--){
        if (nums[i] > nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
        }
    }
    int i = pivot +1, j = n-1;
    while (i <= j){
        swap(nums[i++],nums[j--]);
    }
    // reverse(nums.begin()+pivot+1,nums.end());

    for (int num:nums){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,2,5,4,3};

    nextPermutation(nums); 
    return 0;
}