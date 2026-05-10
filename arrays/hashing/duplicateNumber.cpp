#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// // space complexity: O(n)
// int FindingDuplicate(vector<int>& vec){
//     unordered_set<int> set;
//     for (int i=0; i<vec.size(); i++){

//         if (set.find(vec[i]) != set.end()){
//             return vec[i];
//         }
//         set.insert(vec[i]);

//     }
    
// }

int FindingDuplicate(vector<int>& vec){

    int slow = vec[0], fast = vec[0];

    do{
        slow = vec[slow];
        fast = vec[vec[fast]];
    }while(slow != fast);

    slow = vec[0];
    while(slow != fast){
        slow = vec[slow];
        fast = vec[fast];
    }

    return slow;

    

}


int main(){
    
    vector<int> vec = {1,3,4,2,2};
    int a = FindingDuplicate(vec);
    cout << a << " is repeating";
    return 0;
}