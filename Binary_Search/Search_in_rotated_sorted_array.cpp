#include <iostream>
#include <vector>
using namespace std;

int rotatedArray(vector<int>& nums, int target){

    int n = nums.size();
    int start = 0;
    int end = n-1;

    while (start <=end){

        int mid = start + (end-start)/2;

        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] >= nums[start]){
            if (target >= nums[start] && target <= nums[mid]){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if (target >= nums[mid] && target <=nums[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return 0;

}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 7;

    cout << "index of a target: " << rotatedArray(nums,target);

    return 0;
}