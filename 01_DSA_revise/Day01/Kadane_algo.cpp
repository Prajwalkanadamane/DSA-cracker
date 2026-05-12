#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;  // Edge case: empty array
    
    int maxSum = INT_MIN;  // Initialize to smallest possible int
    int currSum = 0;
    
    for (int ele : arr) {
        currSum = max(ele, currSum + ele);  // Choose to start new subarray or continue
        maxSum = max(maxSum, currSum);      // Update global max
    }
    
    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubarraySum(arr);
    cout << ans << endl;  // Output: 6
    
    // Test edge case: all negative
    vector<int> arr2 = {-1, -2, -3};
    cout << maxSubarraySum(arr2) << endl;  // Output: -1
    
    return 0;
}