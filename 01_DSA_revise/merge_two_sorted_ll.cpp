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
    Node* getHead(){
        return head;
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

    Node* merge_two_sorted_ll(Node* h1, Node* h2){
        if (h1 == NULL || h2== NULL){
            return h1 == NULL ? h2 : h1;
        }

        if (h1->data <= h2->data){
            h1->next = merge_two_sorted_ll(h1->next, h2);
            return h1;
        }else{
            h2->next = merge_two_sorted_ll(h1, h2->next);
            return h2;
        }
    }
    void printFromHead(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

};

int main(){
    List l1;
    List l2;
    List l3;

    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l1.printll();
    cout << endl;
    
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    l2.printll();
    cout << endl;

    Node* mergedHead =
        l3.merge_two_sorted_ll(l1.getHead(), l2.getHead());

    cout << "Merged List: ";
    l3.printFromHead(mergedHead);
    return 0;
}