#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force
void subArraySum1(vector<int>& vec, int c){

    int freq = 0;

    for (int i=0; i<vec.size(); i++){
        int sum = 0;
        for (int j=i; j<vec.size(); j++){
            sum += vec[j];

            if (sum == c){
                freq++;
            }
        }    
    }
    cout << "there are " << freq << " subarrays whose sum equals k";
}

//optimal
void subArraySum2(vector<int>& vec, int k){

    vector<int> prefixSum(vec.size()+1, 0);
    int freq = 0;

    for (int i=0; i<vec.size(); i++){
        prefixSum[i+1] = prefixSum[i]+ vec[i];
    }

    unordered_map<int, int> map;
    for (int i=0; i<prefixSum.size(); i++){
        int conjugateVal = prefixSum[i] - k;

        if (map.find(conjugateVal) != map.end()){
            freq += map[conjugateVal];
        }
        map[prefixSum[i]] +=1;
    }
    cout << "there are " << freq << " subarrays whose sum equals k";

}

int main(){

    vector<int> vec = {1, 2, 3, 4, -3, 1, 1};
    int k = 1;
    subArraySum1(vec, k);
    cout << endl;
    subArraySum2(vec, k);
    
    return 0;
}