#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        int data = val;
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

    void push_front(int val){
        Node* nextNode = new Node(val);
        if (head == NULL){
            head = tail = nextNode;
            return;
        }else{
            nextNode->next = head;
            head = nextNode;
        }
    }

    void push_back(int val){
        Node* nextNode = new Node(val){
            if (head == NULL){
                head = tail = nextNode;
                return;
            }else{
                tail->next = nextNode;
                tail = nextNode;
            }
        }
    }

    void pop_front(){
        if (head == NULL){
            cout << "Linked list is empty.";
        }else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if (head == NULL){
            cout << "Linked list is empty.";
        }

        if (head == tail){
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        temp->next = NULL;
    }

    void insert(int val, int pos){
        if (pos < 0){
            cout << "Invalid position entered.";
            return;
        }
        if (pos == 0){
            push_front(val);
        }

    }

};



int main(){

    return 0;
}