// Brute force approach (Big O(n^2))

// #include <iostream>
// #include <algorithm>
// #include <climits>
// using namespace std;
// int main(){

    // int arr[] = {5,4,-1,7,8};
    // int n =5;
    // int maxV = INT_MIN;

//     for (int i=0; i<n; i++){
//         int current_sum = 0;
//         for (int j=i; j<n; j++){
//             current_sum = current_sum + arr[j]; //when j=5(current_sum=5), (j=4,cs=9) j=-1 //our current_sum becomes (9-1=8)
//             maxV = max(maxV,current_sum);                 //but since 9>8 our maxV remains 9 only
            
//         }
//     }
//     cout << maxV <<endl ;
//     return 0;

// }

// Kadane's algorithm

#include <iostream>
#include <climits>
using namespace std;

int main(){

    int arr[] = {5,4,-1,7,8};
    int n =5;
    int maxV = INT_MIN;

    int current_sum = 0;
    for (int i=0; i<n; i++){
        current_sum = current_sum +arr[i];
        maxV = max(maxV,current_sum);

    }
    cout << maxV ;
    return 0;

}

// or kadane's algo can also be implemented as 

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxSubArray(vector<int>& nums) {
//     int maxSum = nums[0];  // Stores max sum found
//     int currentSum = nums[0];  // Tracks current sum

//     for (int i = 1; i < nums.size(); i++) {
//         currentSum = max(nums[i], currentSum + nums[i]);  // Update current sum
//         maxSum = max(maxSum, currentSum);  // Update max sum found
//     }

//     return maxSum;
// }

// int main() {
//     vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//     cout << "Max Sum: " << maxSubArray(nums) << endl;  // Output: 6
//     return 0;
// }
