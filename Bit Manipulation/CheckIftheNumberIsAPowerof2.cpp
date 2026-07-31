#include<bits/stdc++.h>
using namespace std;

// Remove the last set bit(right most bit)

int main(){

    int N1 = 16;
    int N2 = 26;
    int N3 = 8;
    int k = 2; // index position (there'll be no use of the kth bit)

    if((N1 & N1-1) == 0) cout << N1 << " is a Power of two." << endl;
    else cout << N1 << " isn't a Power of two" << endl;

    if((N2 & N2-1) == 0) cout << N1 << " is a Power of two." << endl;
    else cout << N2 << " isn't a Power of two" << endl;

    if((N3 & N3-1) == 0) cout << N1 << " is a Power of two." << endl;
    else cout << N3 << " isn't a Power of two" << endl;


    return 0;
}