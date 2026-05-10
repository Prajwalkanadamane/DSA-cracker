#include <iostream>
#include <string>
using namespace std;

bool isvalid(char ch){
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}

bool validPalindrome (string str){
    int start = 0, end = str.size()-1;
    while (start < end)
    {
        if (!isvalid(str[start])){
            start++; continue;
        }
        if (!isvalid(str[end])){
            end--; continue;
        }
        if (tolower(str[start]) != tolower(str[end])){
            return false;
        }
        start++; end--;
    }
    return true;
    

}

int main(){
    string str = "race %$car";
    if (validPalindrome (str)){
        cout << "The stirng " << str << " is Palindrome.";
    }else{
        cout << "The stirng " << str << " not a Palindrome.";    
    }
    

    return 0;
}