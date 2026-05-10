#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;  //This means next is a pointer that stores the address of another Node object.

    Node(int val){
        data = val;
        next = NULL;
    }

};

class List{
    Node* head;
    Node* tail;
     
public:
    List(){
        head = tail = NULL;
    }

    //push_front
    void push_front(int val){
        Node* nextNode = new Node(val); // nextNode is stack pointer which points the memory address of 1st node(head) in heap memory.
        if (head == NULL){
            head = tail = nextNode;
            return;
        }else{
            nextNode->next = head;
            head = nextNode;
        }
    }

    //push_back
    void push_back(int val){
        Node* nextNode = new Node(val); // nextNode is stack pointer which points the memory address of 1st node(head) in heap memory.
        if (head == NULL){
            head = tail = nextNode;
            return;
        }else{
            tail->next = nextNode;
            tail = nextNode;
        }
    }

    void pop_front(){
        if (head == NULL){
            cout << "linked list is empty.";
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if (head == NULL){
            cout << "Linked list is empty" << " ";
        }

        if (head == tail){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        temp->next = NULL; 
    }

    void insert(int val, int pos){
        if (pos < 0){
            cout << "invalid position.";
            return;
        }
        if (pos == 0){
            push_front(val);
        }

        Node* temp = head;
        for (int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
       
    }

    void printll(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.printll();

    cout << endl;
    ll.pop_front();
    ll.printll();

    cout << endl;
    ll.pop_back();
    ll.printll();

    cout << endl;
    ll.insert(100, 1);
    ll.printll();


    return 0;
}