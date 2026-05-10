#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};
    // vector<int> :: iterator it;
    // vector<int> :: reverse_iterator it;
    // for (it=arr.begin(); it!=arr.end(); it++){
        // cout << *(it)  << " ";
    // }
    for (auto it=arr.rbegin(); it!=arr.rend(); it++){
        cout << *(it)  << " ";
    }
    // for (it=arr.rbegin(); it!=arr.rend(); it++){
    //     cout << *(it)  << " ";
    // }

    return 0;
}