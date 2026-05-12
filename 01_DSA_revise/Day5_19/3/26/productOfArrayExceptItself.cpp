#include<iostream>
#include<vector>
using namespace std;

vector<int> solution1(vector<int>& nums){
    vector<int> prefix(nums.size(), 0);
    vector<int> suffix(nums.size(), 0);
    vector<int> answer(nums.size(), 0);

    prefix[0] = 1;
    suffix[nums.size()-1] = 1;

    for (int i=1; i<nums.size(); i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    for (int i=nums.size()-2; i>=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    for (int i=0; i<answer.size(); i++){
        answer[i] = suffix[i] * prefix[i];
    }

    return answer;

}

vector<int> solution2(vector<int> nums){

    vector<int> ans(nums.size(), 0);
    ans[0] = 1;
    
    int prefix = 1;
    for (int i=1; i<nums.size(); i++){
        prefix = prefix * nums[i-1];
        ans[i] = prefix;
    }

    int suffix = 1;
    for (int i=nums.size()-2; i>=0; i--){
        suffix = suffix * nums[i+1];
        ans[i] = ans[i] * suffix;
    }

    return ans;
}

int main(){

    vector<int> nums = {1, 2, 3, 4};
    cout << "Given array: " ;
    for (int elem : nums){
        cout << elem << " ";
    }
    cout << endl;

    // vector<int> answer = solution1(nums);
    vector<int> answer = solution2(nums);

    cout << "Product of array except itself: ";
    for (int elem : answer){
        cout<< elem << " ";
    }
    cout << endl;

    return 0;
}