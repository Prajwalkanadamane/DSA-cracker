#include<iostream>
#include<vector>
#include<queue>
#include<string>
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

static int idx = -1;
Node* buildTree(vector<int>& preorder){
    idx++;

    if (preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

bool isBST(Node* root, Node* min, Node* maxi){

    if (root == nullptr) return true;

    if (min != nullptr && root->data <= min->data){
        return false;
    }

    if (maxi != nullptr && root->data >= maxi->data){
        return false;
    }

    return isBST(root->left, min, root) && isBST(root->right, root, maxi);

}

int main(){
    vector<int> preorder = {5, 1, -1, -1, 6, 3, -1, -1, 7, -1, -1};
    Node* root = buildTree(preorder);

    if (isBST(root, nullptr, nullptr)){
        cout << "Valid BST" << endl;
    }else{
        cout<< "Non-valid BST" << endl;
    }

    return 0;
}