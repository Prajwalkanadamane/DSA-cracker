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

void printing(Node* root){
    if (root == NULL){
        return;
    }

    cout << root->data << " ";
    printing(root->left);
    printing(root->right);
}

// level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL){
            q.push(curr->left);
        }

        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << endl;

}


// level order traversal with new line after each level
void levelOrderTraversal1(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if (curr == NULL){
            if (!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != NULL){
            q.push(curr->left);
        }

        if (curr->right != NULL){
            q.push(curr->right);
        }
    }

}

int sumTree(Node* root){

    if (root == NULL){
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum + rightSum;

    return root->data; 
}

void preOrder(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}


int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    
    // printing(root);
    // levelOrderTraversal(root);

    // levelOrderTraversal1(root);
    sumTree(root);
    preOrder(root);

}