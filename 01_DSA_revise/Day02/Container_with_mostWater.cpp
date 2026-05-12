#include<iostream>
#include<vector>
using namespace std;

int Solve(vector<int>& height){

    int max_height = 0;
    int st = 0;
    int end = height.size()-1;

    while(st <= end){
        int ht = min(height[st], height[end]);
        int area = ht * (end-st);
        max_height = max(max_height, area);

        if (height[st] > height[end]){
            end--;
        }else{
            st++;
        }
    }

    return max_height;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int ans = Solve(height);
    cout << ans << endl;

    return 0;
}