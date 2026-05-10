#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    queue<int> q2;
    q2.swap(q);

    cout << "size of q: " << q.size() << endl; //LIFO?
    cout << "size of q2: " << q2.size() << endl; //LIFO?
    return 0;
}