// #include <iostream>
// using namespace std;

// int main(){
//     int n = 16;
//     for (int i=2; i*i<=n; i++){
//         if (n%i == 0){
//             cout << "non_prime."; break;
//         }else{
//             cout << "prime.";
//         }
//     }
//     return 0;
// }

// theorm

#include <iostream>
#include <vector>
using namespace std;

int countPrimeNumbers(int n){
    vector<bool> isPrime(n+1,true);
    int count = 0;

    for (int i=2; i<n; i++){
        if (isPrime[i]){
            count++;

            for (int j=i*2; j<n; j=j+i){
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout << "enter ua value: ";
    cin >> n;

    cout << "total number of prime numbers are: " << countPrimeNumbers(n);
}