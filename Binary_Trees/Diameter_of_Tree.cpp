#include<iostream>
#include<vector>
#include<queue>
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

int height(Node* root){

    if (root == NULL){
        return 0;
    }
    
    int leftHT = height(root->left);
    int rightHT = height(root->right);
    
    return max(leftHT, rightHT)+1;
}

int Diameter(Node* root){
    
    if (root == NULL){
        return 0;
    }

    int leftDiam = Diameter(root->left);
    int rightDiam = Diameter(root->right);
    int currDiam = height(root->left) + height(root->right);

    return max(currDiam, max(leftDiam, rightDiam));

}

int main(){

    vector<int> Tree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(Tree);

    cout << "Diameter of a Tree is: " << Diameter(root) << endl;
}

// One more parallel and optimize approach is just keep calculating the Diameter in the hight function that's it and all sort
// Like this :

// int height(Node* root){

        // int ans = 0

//     if (root == NULL){
//         return 0;
//     }
    
//     int leftHT = height(root->left);
//     int rightHT = height(root->right);

        // ans = max(ans, leftHT+rightHT)
    
//     return max(leftHT, rightHT)+1;
// }