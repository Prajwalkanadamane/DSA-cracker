#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Brute force

void BruteForce(vector<int>& vec, int target){
    
    for (int i=0; i<vec.size(); i++){
        for (int j=i+1; j<vec.size(); j++){
            int sum = 0;
            sum = vec[i] + vec[j];
            if (sum == target){
                cout << target <<" is a sum of elements at indecis " << i << " and " << j;
                return;
            }
        }
    }
    cout << "Sum isn't found! sorry";

}


// If sorted Optimal Approach O(nlogn)
void BruteForce1(vector<int>& vec, int target){
    sort(vec.begin(), vec.end());
    int i=0, j=vec.size()-1;

    while(i<j){
        if ((vec[i] + vec[j]) == target){
            cout << "target is sum of elements at indices " << i << " and " << j;
            return;
        }else if((vec[i] + vec[j]) > target){
            j--;
        }else{
            i++;
        }
    }
    cout << "Sum isn't found! sorry";
}

void Optimized(vector<int>& vec, int target){
    unordered_map<int,int> map;

    vector<int> ans;
    for (int i=0; i<vec.size(); i++){
        int a = target - vec[i];
        if (map.find(a) != map.end()){
            ans.push_back(map[a]);
            ans.push_back(i);
        }
        map[vec[i]] = i;
    }
    for (auto ele:ans){
        cout << ele << " ";
    }

}

int main(){
    vector<int> vec = {5, 2, 11, 7, 15};
    int target = 9;
    // BruteForce(vec, target);
    Optimized(vec,target);
    return 0;
}