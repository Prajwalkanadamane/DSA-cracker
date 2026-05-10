#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class list{

    Node* head; Node* tail;
    public:

    list(){
        head = tail = NULL;
    }

    void pushF(int val){
        Node* new_Node = new Node(val);
        if(head == NULL){
            head = tail = new_Node;
            return;
        }else{
            new_Node->next = head;
            head = new_Node;
        }
    }

    void pushB(int val){
        Node* new_Node = new Node(val);
        if(head == NULL){
            head = tail = new_Node;
            return;
        }else{
            tail->next = new_Node;
            tail = new_Node;
        }
    }

    void popF(){
        if (head == NULL){
            cout << "Linked list is empty!" << " ";
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void popB(){
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
            cout << "Invalid position!" << " ";
            return;
        }

        if (pos == 0){
            pushF(val);
        }

        Node* temp = head;
        for (int i=0; i<pos-1; i++){
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position is out of bounds!" << " ";
        return;
        }

        Node* new_Node = new Node(val);
        new_Node->next = temp->next;
        temp->next = new_Node;

        if (new_Node->next == NULL) {
        tail = new_Node;
        }
    }

    int Search(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if (key == temp->data){
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        return 0;
    }

    void printL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){

    list l1;
    l1.pushF(1);
    l1.pushF(2);
    l1.pushF(3);

    l1.pushB(4);
    l1.pushB(5);
    l1.pushB(6);

    l1.popF();
    l1.popF();

    l1.popB();
    l1.popB();

    l1.insert(5, 2);

    l1.printL();
    
    int key = 4;
    if (l1.Search(key) == 0){
        cout << "Key not found";  
    }else{
        cout << "Key found at idx " << (l1.Search(key));
    }
    

    return 0;
}