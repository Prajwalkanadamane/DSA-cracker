// linear search Big O(n)
// #include <iostream>
// #include <vector>
// using namespace std;

// int singleElement(vector<int>& nums){

//     int n = nums.size();
    
//     for (int i=0; i<n-1; i=i+2){
//         if (i==n-1 || nums[i] != nums[i+1]){
//             return nums[i];
//         }
//     }
//     return 0;
// }


// int main(){
//     vector<int> sorted_nums = {1,1,2,3,3,4,4,8,8};
//     vector<int> sorted_nums_2 = {3,3,7,7,10,11,11};

//     cout << "single element in array is: " << singleElement(sorted_nums);
//     cout << "\nsingle element in array is: " << singleElement(sorted_nums_2);

//     return 0;
// }

// binary search Big O(log n)
#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int>& nums){

    int n = nums.size();
    int start = 0;
    int end = n-1;

    if (n==1){
        return nums[0];
    }

    while (start <= end ){

        int mid = start + (end-start)/2;

        if(mid == 0 && nums[0] != nums[1]){
            return nums[0];
        }
        
        if(mid == n-1 && nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
    
        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }

        if (mid % 2 == 0){
            if (nums[mid] == nums[mid-1]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if (nums[mid] == nums[mid-1]){
                start = mid+1;
            }
            else{
                end = end-1;
            }
        }

    }
    
    return 0;
}


int main(){
    vector<int> sorted_nums = {1,1,2,3,3,4,4,8,8};
    vector<int> sorted_nums_2 = {10,10,4,4,7,11,11,12,12,2,2}; //still works even array is'nt in sorted condition 

    cout << "single element in array is: " << singleElement(sorted_nums);
    cout << "\nsingle element in array is: " << singleElement(sorted_nums_2);

    return 0;
}