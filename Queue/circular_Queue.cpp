#include <iostream>
using namespace std;

class CircularQueue{

    int* arr;
    int currSize, capacity;
    int f, r;

public:
    CircularQueue(int size){
        capacity = size;
        currSize = 0;
        arr = new int[capacity];
        f = 0; r = -1;

    }

    void push(int data){
        if (currSize == capacity){
            cout << "Queue is full!" << endl;
            return;
        }

        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;

    }

    void pop(){
        if (empty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        f = (f+1) % capacity;
        currSize--;

    }

    int front(){
        if (empty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[f];

    }

    bool empty(){
        return currSize == 0;
         
    }

    void printQueue(){
        for (int i=0; i<capacity; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    CircularQueue q(3);

    q.push(11);
    q.push(15);
    q.push(12);
    q.pop();
    q.push(14);


    // q.printQueue();

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}