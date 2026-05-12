#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> solution1(vector<int>& arr){

    int n = arr.size();
    vector<vector<int>> ans;
    
    set<vector<int>> s;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k=j+1; k<n; k++){
                if ((arr[i] + arr[j] + arr[k]) == 0){
                    vector<int> trip = {arr[i], arr[j], arr[k]};
                    sort(trip.begin(), trip.end());
                    if (s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;

}

vector<vector<int>> solution2(vector<int>& arr){

    int n = arr.size();
    set<vector<int>> triplets;
    
    for (int i=0; i<n; i++){
        int tar = -arr[i];
        set<int> s;
        for (int j=i+1; j<n; j++){
            int third = tar - arr[j];
            
            if (s.find(third) != s.end()){
                vector<int> trip = {arr[i], arr[j], third};
                sort(trip.begin(), trip.end());
                triplets.insert(trip);
            }
            s.insert(arr[j]);
        }
        
    }
    vector<vector<int>> ans(triplets.begin(), triplets.end());
    return ans;
}


int main(){

    vector<int> arr  {-1,0, 1, 2, -1, -4};
    vector<vector<int>> ans = solution1(arr);
    for (int i=0; i<ans.size(); i++){
        cout << "{";
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "}"; 
    }
    cout << endl;
    return 0;
}