#include <iostream>
using namespace std;

int SumOfNum(int n){

    if (n == 1){
        return 1;
    }
    return n+SumOfNum(n-1);

}

int main(){
    
    cout << SumOfNum(5);
    return 0;
}