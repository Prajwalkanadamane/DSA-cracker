#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);

    l.pop_back();
    l.pop_front();

    for (int val : l){
        cout << val << " ";
    }
    cout << endl;
    // cout << l[2]; random access not available


    return 0;
}
