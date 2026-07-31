#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1, 2, 3};

    int n = arr.size();

    int subsets = 1 << n; // 2powern
    vector<vector<int>> ans;

    for (int num = 0; num <subsets; num++){
        vector<int> list;
        for (int i=0; i<n; i++){
            if (num & (1 << i)){
                list.push_back(arr[i]);
            }
        }
        ans.push_back(list);
    }

    for(int row = 0; row<ans.size(); row++){
        for (int clm = 0; clm<ans[row].size(); clm++){
            cout << ans[row][clm] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}