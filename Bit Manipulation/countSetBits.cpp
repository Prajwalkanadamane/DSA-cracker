#include <iostream>
using namespace std;

int main() {
   int num = 22; // Binary: 10110
   cout << "Number of 1's: " << __builtin_popcount(num) << endl; // Output: 3
   return 0;
}