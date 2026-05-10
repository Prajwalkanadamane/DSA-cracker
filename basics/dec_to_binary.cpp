#include <iostream>
using namespace std;

void dec_to_binary(int num){

    int ans = 0;
    int pow = 1;

    while(num > 0){
        int rem = num % 2;
        num = num / 2;

        ans += rem*pow;
        pow *= 10;
    }
    cout << ans << endl;
}

int main(){
    for (int i=0; i<11; i++){
        dec_to_binary(i);
    }
    return 0;
}