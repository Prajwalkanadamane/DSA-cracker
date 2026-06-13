#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
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
        Node* nextNode = new Node(val);
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
            cout << "Linked list is empty.";
            return;
        }
        Node* temp = head;
        head = head->next;
        
        if (head == NULL){
            tail = NULL;
        }
        delete temp;
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
        while(temp->next->next != NULL){
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
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;

        for (int i=0; i<pos-1; i++){
            if (temp == NULL){
                cout << "Invalid position." << endl;
                return;
            }else{
                temp = temp->next;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }

    void print(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};


int main(){

    List ll;

    cout << "Adding elements at back:" << endl;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print();

    cout << "\nAdding element at front:" << endl;
    ll.push_front(5);
    ll.print();

    cout << "\nInsert 15 at position 2:" << endl;
    ll.insert(15, 2);
    ll.print();

    cout << "\nDelete front:" << endl;
    ll.pop_front();
    ll.print();

    cout << "\nDelete back:" << endl;
    ll.pop_back();
    ll.print();

    return 0;
}