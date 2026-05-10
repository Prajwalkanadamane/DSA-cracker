#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l++] != str[r--]) return false;
    }
    return true;
}

int main() {
    string s = "abaaba";
    string ans = "";
    int maxLen =0;
    for (int i = 0; i < s.length(); i++) {
        for (int len = 1; len <= s.length() - i; len++) {
            string sub = s.substr(i, len);
            if (isPalindrome(sub) && sub.length()>maxLen) {
                maxLen = sub.length();
                ans = sub;
                
            }
        }
    }
    cout << ans;

    return 0;
}
