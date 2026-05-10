#include<iostream>
#include<vector>
using namespace std;

vector<int> pre;

void queury(vector<int>& vec){

    pre.resize(vec.size());
    pre[0] = vec[0];
    for (int i=1; i<vec.size(); i++){
        pre[i] = vec[i]+pre[i-1];
    }

    for (int ele=0; ele<pre.size(); ele++){
        cout << pre[ele] << " ";
    }
    cout << endl;
}

int rangesum(int left, int right){
    if (left == 0) {
        return pre[right];
    };
    return pre[right] - pre[left-1];
}



int main(){
    vector<int> vec = {-2, 0, 3, -5, 2, -1};
    for (auto ele:vec){
        cout << ele << " ";
    }
    cout << endl;
    int m = 2, n = 5;
    queury(vec);
    cout << "sum from index " << m << "->" << n << " is " << rangesum(m, n);
}