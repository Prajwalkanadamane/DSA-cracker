#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

void Solution(vector<int>& vec, int k){

    unordered_map<int,int> map;
    int left = 0, right = 0, maxc = 0;

    for (right=0; right<vec.size(); right++){
        map[vec[right]] += 1;
        if (map.find(vec[right]) != map.end()){
            k--;
        }
        maxc = max(maxc, right-left+1);    

    }


}

int main(){

    vector<int> vec = {1, 2, 3, 2, 2};
    int k=2;

    return 0;
}