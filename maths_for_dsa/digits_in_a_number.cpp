// //to extract individual digits
// #include <iostream>
// using namespace std;

// void digitsInNumber(int n){
//     while (n !=0 ){
//         int numbers = n % 10;
//         cout << numbers << endl;

//         n = n/10;

//     }
// }

// int main(){
//     int n;
//     cout << "enter ua value: ";
//     cin >> n;

//     cout << "individual numbers are: ";
//     digitsInNumber(n);
// }

// to count our number of digits

// #include <iostream>
// using namespace std;

// void digitsInNumber(int n){
//     int count = 0;
//     while (n !=0 ){
//         int numbers = n % 10;
//         count ++;

//         n = n/10;

//     }
//     cout << count;
// }

// int main(){
//     int n = 3216;
//     cout << "total numbers are numbers are: ";
//     digitsInNumber(n);
// }

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n = 3216;
    cout << "total numbers are numbers are: " << (int) (log10(n)+1);
    return 0;
}