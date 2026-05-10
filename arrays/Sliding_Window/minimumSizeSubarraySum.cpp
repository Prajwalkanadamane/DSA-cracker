#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void Approach1(vector<int>& vec, int target){

    int right = 0, left=0;
    int sum = 0;
    int minimalLenght = INT_MAX;
    for (int right=0; right<vec.size(); right++){
        sum += vec[right];
        while(sum >= target){
            minimalLenght = min(minimalLenght, right-left+1);
            sum = sum - vec[left];
            left++;
        }
    }
    if (minimalLenght == INT_MAX){
        cout << "Failed" << endl;
    }else{
        cout << "minimal Lentgh with sum >= " << target << " is " << minimalLenght << endl;
    }

}

void Approach2(vector<int>& vec, int target){

    int right = 0, left=0;
    int sum = 0;
    int minimalLenght = INT_MAX;

    while(right < vec.size()){
        sum += vec[right];

        while (sum >= target){
            minimalLenght = min(minimalLenght, right-left+1);
            sum = sum - vec[left];
            left++;
            
        }
        right++;
    }
    
    if (minimalLenght == INT_MAX){
        cout << "Failed" << endl;
    }else{
        cout << "minimal Lentgh with sum >= " << target << " is " << minimalLenght << endl;
    }

}



int main(){

    vector<int> vec = {2,3,1,2,4,3};
    int target = 7;

    // Approach(vec, target);
    Approach2(vec, target);
}