// optimized/brute force
// #include <iostream>
// #include <vector>
// using namespace std;

// void sortArray(vector<int>& nums){
//     int n = nums.size();
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;
    
//     for (int i = 0; i<n; i++){

//         if (nums[i] == 0) count0++;
//         else if (nums[i] == 1) count1++;
//         else count2++;

//         int indx = 0;
//         for (int i=0; i<count0; i++){
//             nums[indx++] = 0;
//         }
//         for (int i=0; i<count1; i++){
//             nums[indx++] = 1;
//         }
//         for (int i=0; i<count2; i++){
//             nums[indx++] = 2;
//         }
//     }
//     for (int num:nums){
//         cout << num << " ";
//     }
//     cout << endl;
// }

// int main(){
//     vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
//     sortArray(nums);

//     return 0;
// }

// // using sort function
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void sortArray(vector<int>& nums){
//     sort (nums.begin(),nums.end());
//     for (int num:nums){
//         cout << num << " ";
//     }
//     cout << endl;
// }

// int main(){
//     vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
//     sortArray(nums);

//     return 0;
// }

// using dutch national flag algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortArray(vector<int>& nums){

    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid<=high){
        if (nums[mid] == 0){
            swap (nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else{
            swap (nums[mid],nums[high]);
            high--;
        }
    }
    for (int num:nums){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
    sortArray(nums);

    return 0;
}
