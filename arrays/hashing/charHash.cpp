#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(){
    string s = "abaaacdefggfedcba";
    map<char,int> maping;

    for (int i=0; i<s.size(); i++){
        maping[s[i]] += 1;
    }

    for (auto i:maping){
        cout << i.first <<"->" << i.second << endl;
    }

    int c = 'z';
    cout << maping[c];
    return 0;
}