// // Brute force approach (Big O(n^2))

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int>productOfArrayExcpetSelf(vector<int> &nums){

//     int n = nums.size();
//     vector<int> output(n,1);

//     for (int i=0; i<n; i++){
//         for (int j=0; j<n; j++){
//             if (i != j){
//                 output[i] *= nums[j];
//             }
//         }
//     }
//     return output;
// }

// int main(){
//     vector<int> nums = {1,2,3,4};
//     vector<int> output = productOfArrayExcpetSelf(nums);

//     cout << "Prodcut of Array except self is: ";
//     for (int num : output){
//         cout << num << " ";

//     }
//     cout << endl;
//     return 0;
// }

// optimum solution (BIg O(n))

#include <iostream>
#include <vector>
using namespace std;

vector<int>productOfArrayExcpetSelf(vector<int> &nums){

    int n = nums.size();
    vector<int> output(n,1);
    
    int left = 1; 
    for (int i=0; i<n; i++){
        output[i] = left;
        left = left*nums[i];
    }
    
    int right = 1;
    for (int i=n-1; i>=0; i--){
        output[i] *= right;
        right = right*nums[i];
    }

    return output;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> output = productOfArrayExcpetSelf(nums);

    cout << "Prodcut of Array except self is: ";
    for (int num : output){
        cout << num << " ";

    }
    cout << endl;
    return 0;
}
