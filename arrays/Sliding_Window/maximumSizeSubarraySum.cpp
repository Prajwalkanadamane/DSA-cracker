#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void Solution(vector<int> vec, int target){

    int left = 0, right = 0;
    int sum = 0; 
    int maxL = INT_MIN;
    
    for (int right=0; right<vec.size(); right++){
        sum += vec[right];

        while(sum > target){
            sum -= vec[left];
            left++;
            
        }
        if (sum <= target){
            maxL = max(maxL, right-left+1);
        }      
    }

    if (maxL == INT_MIN){
        cout << "Failed" << endl;
    }else{
        cout << "maximum Lentgh with sum <= " << target << " is " << maxL << endl;
    }
}

int main(){
    vector<int> vec = {2,5,1,7,10};
    int target = 14;
    Solution(vec, target);
}