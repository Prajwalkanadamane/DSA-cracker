#include<iostream>
#include<vector>
using namespace std;

bool Solve(vector<int>& vec, int k, int idx,vector<vector<int>>& ans, vector<int>& temp, int sum){

    if (idx == vec.size()){
        if (sum == k){
            ans.push_back({temp});
            return true;
        }
        return false;
    }

    temp.push_back(vec[idx]);
    sum += vec[idx];
    if(Solve(vec, k, idx+1, ans, temp,sum)) return true;

    sum -= vec[idx];
    temp.pop_back();
    if (Solve(vec, k, idx+1, ans, temp,sum)) return true;

    return false;

}

int main(){
    vector<int> vec = {1, 2, 1};
    int k = 2;
    int idx = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    Solve(vec, k, idx, ans, temp, sum);

    // cout<< ans.size();

    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}