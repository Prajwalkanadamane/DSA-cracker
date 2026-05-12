#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

void solve(vector<int>& num){

    for (int i=0; i<num.size(); i++){
        if (num[i] == 0){
            num[i] = -1;
        }
    }
    vector<int> prefixSum(num.size(), 0);
    prefixSum[0] = num[0];

    for (int i=1; i<num.size(); i++){
        prefixSum[i] = prefixSum[i-1] + num[i];
    }

    unordered_map<int, int> map;
    map[0] = -1;

    int maxL = INT_MIN;

    for (int i=0; i<prefixSum.size(); i++){

        if (map.find(prefixSum[i]) != map.end()){
            maxL = max(maxL, i-map[prefixSum[i]]);
        }else{
            map[prefixSum[i]] = i;
        }
    }   
    
    for (int nums : prefixSum){
        cout << nums << " ";
    }
    cout << endl;
    cout <<"Maximum length of a contiguous subarray: " << maxL << endl;


}

int main(){

    vector<int> num = {0,0,1,0,0,0,1,1};
    for (int ele : num){
        cout << ele << " ";
    }
    cout << endl;
    solve(num);
    return 0;
}