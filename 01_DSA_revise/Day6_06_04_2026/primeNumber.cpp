#include<iostream>
using namespace std;

int main(){

    int n = 20;

    for (int i=0; i<=n; i++){
        bool isPrime = true;

        for (int j=2; j<i; j++){
            if (i % j == 0){
                isPrime = false;
                break;
            }
        }
        if (isPrime){
            cout << i << " ";
        }
    }

    return 0;
}