#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }

};

class Double_LL{

    Node* head;
    Node* tail;
    public:

    Double_LL(){
        head = tail = NULL;
    }

    void pushF(int val){
        Node* newNode = new Node(val);
        
        if (head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushB(int val){
        Node* newNode = new Node(val);
        
        if (head == NULL){
            head = tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popF(){
        if (head == NULL){
            cout << "Invalid";
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;

    }

    void popB(){
        if (head == NULL){
            cout << "Invalid";
        }

        if(head == tail){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }

        tail->prev = NULL;
        delete tail;
        tail = temp;
        tail->next = NULL;
     
    }

    void printL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next; 
        }
        cout << "NULL";
    }
};

int main(){

    Double_LL dll;

    dll.pushF(1);
    dll.pushF(2);
    dll.pushF(3);

    dll.pushB(1);
    dll.pushB(2);
    dll.pushB(3);

    dll.popF();
    dll.popF();
    dll.popF();

    dll.popB();
    dll.popB();
    dll.popB();



    dll.printL();
    return 0;
}