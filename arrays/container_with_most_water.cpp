// // # brute force BigO(n^2)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int maxWater(vector<int> arr){

//     int n = arr.size();
//     int maxWter = 0;

//     for (int i=0; i<n; i++){
//         int width = 0;
//         for (int j=0; j<n; j++){
            
//             int height = min(arr[i],arr[j]);
//             int area = height * width;
//             maxWter = max(maxWter,area);
//             width++;

//         }
//     }
//     return maxWter;
// }

// int main(){
    
//     vector<int> arr = {1,8,6,2,5,4,8,3,7};

//     cout << "maximum water that can be stored: " << maxWater(arr);

//     return 0;
// }


// // # optimum approach BigO(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxWater(vector<int> arr){

    int n = arr.size();
    int maxWter = 0;
    int width = n-1;
    int i=0;
    int j= n-1;

    while (i<j){

        int height = min(arr[i],arr[j]);
        int area = height * width;
        maxWter = max(maxWter,area);

        if (i<j){
            i++;
        }
        else{
            j--;
        }

    }
    
    return maxWter;
}

int main(){
    
    vector<int> arr = {9,8,9,2,5,4,8,3,10};

    cout << "maximum water that can be stored: " << maxWater(arr);

    return 0;
}