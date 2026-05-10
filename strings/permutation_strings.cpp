#include <iostream>
#include <string>
using namespace std;

bool isFreqsame(int freq1[], int freq2[]){
    for(int i=0; i<26; i++){
        if (freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int freq [26] = {0};

    for (int i=0; i<s1.length(); i++){
        freq[s1[i] - 'a']++;
    }

    int windowsize = s1.length();

    for (int i=0; i<s2.length(); i++){
        int windowidx = 0, idx = i;
        int windowfreq[26] = {0};

        while (windowidx < windowsize && idx < s2.length()){
            windowfreq[s2[idx] - 'a']++;
            windowidx++; idx++;
        }

        if (isFreqsame(freq,windowfreq)){
            return true;
        }
    }
    return false;
}


int main(){
    string a = "tui";
    string b = "eiubaiutoo";
    if (checkInclusion (a,b)){
        cout << "Permutation in string.";
    }else{
        cout << "No Permutation in string.";    
    }

    return 0;
}