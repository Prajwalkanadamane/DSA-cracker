#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string& s){
        while( i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    int f(int i, int n, string& s){

        if (i == n) return 0;
        int miniPartition = 1e9;
        for (int j=i; j<n; j++){
            if (isPalindrome(i, j, s)){
                int partition = 1 + f(j+1, n, s);
                miniPartition = min(miniPartition, partition); 
            }
        }

        return miniPartition;

    }

int f2(int i, int n, string& s, vector<int>& DP){

        if (i == n) return 0;
        if (DP[i] != -1) return DP[i];
        int miniPartition = 1e9;
        for (int j=i; j<n; j++){
            if (isPalindrome(i, j, s)){
                int partition = 1 + f2(j+1, n, s, DP);
                miniPartition = min(miniPartition, partition); 
            }
        }

        return DP[i] = miniPartition;

    }

int palindromePartitioning(string s){
        int n = s.size();
        vector<int> DP(n+1, 0);
        DP[n] = 0;

        for (int i=n-1; i>=0; i--){
            int miniPartition = 1e9;
            for (int j=i; j<n; j++){
                if (isPalindrome(i, j, s)){
                    int partition = 1 + DP[j+1];
                    miniPartition = min(miniPartition, partition); 
                }
            }
            DP[i] = miniPartition;

        }
        return DP[0]-1;
    
}

int main(){
    string s = "bababcbadcede";
    int n = s.size();
    vector<int> DP(n, -1);
    cout << "Minimum parition required to make a string palindrome: " << f(0, n, s) -1 << endl;
    cout << "Minimum parition required to make a string palindrome MEMO: " << f2(0, n, s, DP) -1 << endl;
    cout << "Minimum parition required to make a string palindrome TABU: " <<  palindromePartitioning(s) << endl;

    return 0;
}