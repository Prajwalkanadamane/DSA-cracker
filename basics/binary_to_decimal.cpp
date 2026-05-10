#include <iostream>
using namespace std;

void binary_to_deciaml(int num){

    int ans = 0;
    int pow = 1;

    while(num > 0){
        int rem = num % 10;
        num = num / 10;

        ans += rem*pow;
        pow *= 2;
    }
    cout << ans << endl;
}

int main(){
    
    binary_to_deciaml(1111);
    return 0;
}