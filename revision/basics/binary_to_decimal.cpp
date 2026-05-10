#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void binary_decimal(string number){
    int ans = 0;
    int s = number.size();
    for (int i=0; i<s; i++){
        if (number[i] == '1'){
            ans += pow(2,s-1-i);
        }
    }
    cout << "binary " << number << " decimal conversion is: " << ans << endl;

}

int main(){
    string number = "1010";
    binary_decimal(number);
}