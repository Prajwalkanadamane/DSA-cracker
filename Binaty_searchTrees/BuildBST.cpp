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

Node* BobTheBuilder(Node* root, int val){

    if (root == nullptr) return new Node(val);

    if (val < root->data){
        root->left = BobTheBuilder(root->left, val);
    }else{
        root->right = BobTheBuilder(root->right, val);
    }

    return root;

}

Node* BuildTree(vector<int>& arr){
    Node* root = nullptr;

    for (auto elem : arr){
        root = BobTheBuilder(root, elem);
    }

    return root;

}

void Inorder(Node* root){
    
    if (root == nullptr) return;
    
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

bool SearchKey(Node* root, int key){

    if (root == nullptr) return false;

    if (root->data == key) return true;

    if (key < root->data){
        return SearchKey(root->left, key);
    }else{
        return SearchKey(root->right, key);
    }
    

}

Node* getInorderSuccessor(Node* root){
    while(root != nullptr && root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key){
    if (root == nullptr){
        return root;
    }

    if (key < root->data){
        root->left = delNode(root->left, key);
    }

    else if (key > root->data){
        root->right = delNode(root->right, key);

    }else{
        //key == root
        if (root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }

    return root;

}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = BuildTree(arr);

    int key = 5;
    cout << "Before:";
    Inorder(root);
    cout << endl;
    // bool result = SearchKey(root, key);
    
    // if (result){
        //     cout << "Key is found." << endl;
        // }else{
            //     cout << "Key not found." << endl;
            // }
            
    delNode(root, key);
    cout << "After:";
    Inorder(root);
    cout << endl;

    return 0;
}