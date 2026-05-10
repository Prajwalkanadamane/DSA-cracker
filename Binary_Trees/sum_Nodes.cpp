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

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if (preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);// Once the result (even NULL) comes back, it gets assigned, and the function continues to next line
    root->right = buildTree(preorder);
    //Finally, after both left and right are assigned, the function returns the root, which then gets assigned to its parent’s child pointer (left or right)
    return root;

}

int sum(Node* root){
    if (root == NULL){
        return 0;
    }

    int leftCount = sum(root->left);                                                              
    int rightCount = sum(root->right);
    return leftCount + rightCount + root->data;

}

int main(){
    vector<int> preorder ={1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Sum : " << sum(root);
    return 0;
} 