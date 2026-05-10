
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int majorityElement(vector<int> &arr){

//     sort(arr.begin(),arr.end());
//     int n = arr.size();
//     int freq = 1;

//     for (int i=0; i<n-1; i++){
//         if (arr[i] == arr[i+1]){
//             freq++;
//         }
//         else{
//             freq=1;
//         }
//         if (freq > n/2){
//             return arr[i];
//         }

//     }
//     return -1;

    

// }

// int main(){
//     vector<int> arr = {2,2,1,1,1,2,2};

//     cout << "majority element is: " << majorityElement(arr);

//     return 0;
// }