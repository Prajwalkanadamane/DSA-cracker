#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void solution(vector<int>& vec, int k){

    int left =0;
    int right=0;
    int maxL = INT_MIN;
    int reborn = k;
    int zeros = 0;

    for (right=0; right<vec.size(); right++){

        if (vec[right] == 0){
            zeros++;
        }

        while(zeros > k){
            if (vec[left] == 0){
                zeros--;
            }
            left++;

        }

        maxL = max(maxL, right-left+1);
    }
    cout << maxL;
}

int main(){
    vector<int> vec = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    solution(vec, k);
    return 0;
}