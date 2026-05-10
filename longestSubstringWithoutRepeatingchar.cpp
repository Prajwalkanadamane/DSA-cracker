#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;

void LongestSubString(string s){

    unordered_map<char,int> m;

    int size = 0;
    int maxSize = 1;

    for (int i=0; i<s.size(); i++){
        if (m.find(s[i]) != m.end()){
            size = 0;
        }
        m[s[i]] += 1;
        size++;
        maxSize = max(size, maxSize);
    }

    cout << maxSize;

}



int main(){
    string s = "pwwkew";
    LongestSubString(s);
    return 0;
}