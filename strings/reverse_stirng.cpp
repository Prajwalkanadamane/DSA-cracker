#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string s){
    int size = s.length();
    string ans = "";

    reverse(s.begin(),s.end());

    for (int i=0; i<size; i++){
        string word = "";
        while (i<size && s[i] != ' '){
            word += s[i];
            i++;
        }
        if (word.length() > 0){
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main(){
    string s = "the pen";
    cout << "the reversed string is: " << reverseString(s);
    
    return 0;
}