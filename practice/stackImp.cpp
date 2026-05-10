#include<iostream>
#include<vector>
#include<list>
using namespace std;

// // using vector

// class Stack{
//     vector<int> v;

//     public:

//     void push(int val){
//         v.push_back(val);
//     }

//     void pop(){
//         v.pop_back();
//     }

//     int top(){
//         return v[v.size()-1];
//     }

//     void print(){
//         for (int val:v){
//             cout << val << endl;            
//         }
//     }

// };

// Using Linked list

class Stack{
    list<int> ll;

    public:

    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }
    
    bool empty(){
        return ll.size() == 0;
    }

};

int main(){

    Stack ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.push(7);

    ll.pop();
    ll.pop();
    cout << endl;
    
    while(ll.empty()){
        cout << ll.top() << " ";
    }
    cout << endl;

    cout << "The top most element is:" << ll.top() << endl;
    // ll.print();
    return 0;
}