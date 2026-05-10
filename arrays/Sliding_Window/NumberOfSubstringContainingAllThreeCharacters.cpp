#include<iostream>
#include<string>
using namespace std;


void Solution(string& s){


    int count = 0;
    int arr[3] = {-1, -1, -1};

    for (int i=0; i<s.size(); i++){

        arr[s[i] - 'a'] = i;

        if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
            int minIndex = min(arr[0], min(arr[1], arr[2]));
            count += minIndex + 1;
        }
    }

    cout << count;
}

int main(){

    string s = "abcabc";
    Solution(s);
    return 0;
}