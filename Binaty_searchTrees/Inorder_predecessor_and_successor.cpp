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

Node* rightMostIN_leftsubTree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->right;
    }

    return ans;
}

Node* leftMostIN_rightsubTree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }

    return ans;
}

vector<int> getPreSucc(Node* root, int key){

    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if (key < curr->data){
            succ = curr;
            curr = curr->left;
        }else if (key > curr->data){
            pred = curr;
            curr = curr->right;
        }else{
            if (curr->left){
                pred = rightMostIN_leftsubTree(curr->left);
            }

            if (curr->right){
                succ = leftMostIN_rightsubTree(curr->right);
            }
            break;
        }
    }
    int predVal = (pred) ? pred->data : -1;  // -1 indicates no predecessor
    int succVal = (succ) ? succ->data : -1;  // -1 indicates no successor
    return {predVal, succVal};
}

int main(){
    vector<int> vec = {1, 4, 5, 6, 7, 8, 9};

    Node* root = builBST(vec);
    // inorder(root);

    int key = 7;

    vector<int> ans = getPreSucc(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;
    cout << endl;
    return 0;
}