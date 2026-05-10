//print 1 to n

#include <iostream>
using namespace std;

void printNum(int num){
    if (num == 0){
        return;
    }
    printNum(num-1);
    cout << num << endl;
}

int main(){
    int num = 5;

    printNum(num);
    return 0;
}