#include <iostream>
using namespace std;

// int gcd(int a, int b){
//     while (a>0 && b>0){
//         if (a>b){
//             a = a % b;
//         }else{
//             b = b % a;
//         }

//     }
//     if (a == 0) return b;
//     return a;
// }

//using recurssion
int gcdRec(int a, int b){
    if (b==0) return a;
    return gcdRec(b, a%b);
}

int lcmRec(int a,int b){
    int gcd = gcdRec(a,b);
    return a*b/gcd;
}

int main(){
    int a = 20, b = 28;

    cout << lcmRec(a,b) << " is our GCD.";
    return 0;
}

// // Brute force approach
// #include <iostream>
// using namespace std;

// int gcd(int a, int b){
//     int gcd = 1;
//     int limit = min(a,b);

//     for (int i=limit; i>=1; i--){
//         if (a%i == 0 && b%i == 0){
//             gcd = i;
//             break;
//         }
//     }
//     return gcd;
// }

// int main(){
//     int a = 20, b = 28;

//     cout << gcd(a,b) << " is our GCD.";
//     return 0;
// }