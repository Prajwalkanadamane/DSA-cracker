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

void preOrderx(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderx(root->left);
    preOrderx(root->right);

}

void PathBuilder(Node* root, string path, vector<string>& ans){
    if (root->left == NULL && root->right == NULL){
        ans.push_back(path);
        return;
    }

    if (root->left) {
        PathBuilder(root->left, path+"->"+to_string(root->left->data), ans);
    }

    if (root->right) {
        PathBuilder(root->right, path+"->"+to_string(root->right->data), ans);
    }

}



int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, -1};
    Node* root = buildTree(preorder);
    // preOrderx(root);
    string path = to_string(root->data);
    vector<string> ans;

    PathBuilder(root, path, ans);

    for (auto ele : ans){
        cout << ele << endl;
    }


    return 0;
}