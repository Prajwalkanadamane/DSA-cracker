// #brute force method (Big O(n^2))

// #include <iostream>
// #include <vector>
// using namespace std;

// int majorityElement(vector<int> &arr){

//     int n = arr.size();
    
//     for (int i=0; i<n; i++){
//         int freq = 0;
//         for (int j=0; j<n; j++){
//             if (arr[i] == arr[j]){
//                 freq++;
//             }
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

// if our array is sorted (Big O(nlogn))

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

// or we can do simply this if array is sorted (Big O(nlogn))

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int majorityElement(vector<int> &arr){

//     sort(arr.begin(),arr.end());
//     int n = arr.size();

//     return arr[n/2];

// }

// int main(){
//     vector<int> arr = {1,4,3,4,5};

//     cout << "majority element is: " << majorityElement(arr);

//     return 0;
// }

// moore's voting algo (linear time complexity Big O(n))

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> arr){
    int count = 0;
    int candidate = 0;
    int n = arr.size();

    for (int i=0; i<n; i++){
        if (count == 0){
            candidate = arr[i];
            
        }
        if (candidate == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    
    //safety check
    int occur = 0;
    for (auto nums:arr){
        if (nums == candidate){
            occur++;
        }
    }
    if (occur > n/2) return candidate; else return -1;
}


int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << "majority element is: " << majorityElement(arr);

    return 0;
}


// 🧠 Intuition Behind Moore's Voting Algorithm

// Think of it like voting in an election:

// You start with a candidate and a vote count = 1.

// Every time you see the same element, you increase the count.

// If it’s a different element, you decrease the count.

// If the count becomes 0, you choose a new candidate.

// The majority element will survive till the end because it appears more than others.