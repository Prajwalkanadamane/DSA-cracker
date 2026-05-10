#include <iostream>
using namespace std;

int main(){
    int number = 10;
    int ans = 0;
    int pow = 1;

    while (number > 0){
        int remainder = number % 2;
        number = number / 2;
        ans += remainder*pow;
        pow *= 10;
    }

    cout << "our number in binary form is: " << ans << endl;
}