#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int right = vec.size()-1;
    cout << "sum of numbers: " << vec[right+1] - vec[0];
    
    return 0;
}