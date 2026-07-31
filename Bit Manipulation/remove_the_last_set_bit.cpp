#include<bits/stdc++.h>
using namespace std;

// Remove the last set bit(right most bit)

int main(){

    int N = 13;
    int k = 2; // index position (there'll be no use of the kth bit)

    cout << (N & N-1);

    return 0;
}