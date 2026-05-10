#include <iostream>
#include <stack>
using namespace std;

// int main(){
//     stack<int> s;

//     s.push(1);
//     s.push(2);
//     s.push(3);

//     cout << s.top() << endl; //LIFO?
//     while (!s.empty()){
//         cout << s.top() << " "; //LIFO
//         s.pop();
//     }
//     return 0;
// }

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    stack<int> s2;
    s2.swap(s);

    cout << "size of s: " << s.size() << endl; //LIFO?
    cout << "size of s2: " << s2.size() << endl; //LIFO?
    return 0;
}