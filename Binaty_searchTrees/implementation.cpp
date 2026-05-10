#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if (root == NULL){
        return new Node(val);
    }
    if (val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

Node* builBST(vector<int>& vec){
    Node* root = NULL;
    for (auto val : vec){
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);


}

int main(){
    vector<int> vec = {3, 2, 1, 5, 6, 4};

    Node* root = builBST(vec);
    inorder(root);
    cout << endl;
    return 0;
}