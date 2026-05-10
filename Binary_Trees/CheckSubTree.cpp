#include<iostream>
#include<vector>
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

// static int idx = -1;
Node* BuildTree(vector<int>& Tree, int& idx){
    idx++;
    
    if (Tree[idx] == -1){
        return NULL;
    }
    
    Node* root = new Node(Tree[idx]);
    root->left = BuildTree(Tree, idx);
    root->right = BuildTree(Tree, idx);
    
    return root;
}

void PreOrder(Node* root){
    
    if (root == NULL){
        return;
    }
    
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

bool isIdentical(Node* root1, Node* root2){
    
    if (root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    
    bool leftroots = isIdentical(root1->left, root2->left);
    bool rightroots = isIdentical(root1->right, root2->right);
    
    return leftroots && rightroots && root1->data == root2->data;
}

bool isSubTree(Node* root1, Node* root2){

    if (root1 == NULL || root2 == NULL){
        return root1 == root2;
    }

    if (root1->data == root2->data && isIdentical(root1, root2)){
        return true;
    }

    bool fromLeft = isSubTree(root1->left, root2);
    bool fromRight = isSubTree(root1->right, root2);

    return fromLeft || fromRight; 
}

int main(){
    vector<int> Tree1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> Tree2 = {3, 4, -1, -1, 5, -1, -1};
    
    
    int idx1 = -1;
    int idx2 = -1;
    Node* root1 = BuildTree(Tree1, idx1);
    Node* root2 = BuildTree(Tree2, idx2);


    bool subTreeResult = isSubTree(root1, root2);
    
    // bool result = isIdentical(root1, root2);
    
    if(subTreeResult){
        cout << "subTree";
    }else{
        cout << "Not a subTree";
    }

    // if(result){
    //     cout << "Tree1 and Tree2 are Identical";
    // }else{
    //     cout << "Tree1 and Tree2 are non-Identical";
    // }
    
    
    // PreOrder(root1);
    // PreOrder(root2);
    return 0;
}


// 🧩 C++ Static Variable in Functions

// Definition:
// A static variable inside a function is created once and persists across all future calls of that function.

// Effect:

// Keeps its previous value between calls

// Not reset automatically

// Stored in data segment (not stack)

// Example Pitfall:

// static int idx = -1;  // Will not reset automatically


// If you call the same recursive function twice (e.g., to build two trees),
// idx will continue from its previous value → ❌ causes undefined behavior.

// ✅ Solution:

// Reset static manually:

// idx = -1;


// before calling function again.

// OR (better): Use a local variable passed by reference.

// Node* BuildTree(vector<int>& Tree, int& idx);

// 💎 Memory Insight:
// Variable Type	Lifetime	Scope	Stored In
// Local Variable	Temporary	Function	Stack
// Static Variable	Program lifetime	Function	Data Segment
// Global Variable	Program lifetime	Global	Data Segment
// 🧠 Key Takeaway:

// “Static variables remember — so if you don’t reset them, they’ll remember your mistakes too.”