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

int height(Node* root){
    if (root == NULL){
        return 0;
    }

    int leftHT = height(root->left);                /*Pauses the current function (height(1)).
                                                    Jumps into height(2) and starts executing it.
                                                    When height(2) finishes (i.e., hits a return), it:
                                                    Gives the result back to height(1),
                                                    Resumes the next line in height(1) (which is rightHT = height(root->right)).*/
    int rightHT = height(root->right);
    return max(leftHT, rightHT) + 1;

}

int main(){
    vector<int> preorder ={1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Height: " << height(root) << endl;
    return 0;
} 

//Function Call Chain and Stack Behavior

/*height(1)
  ├── height(2)
  │     ├── height(NULL) → returns 0 (left)
  │     └── height(NULL) → returns 0 (right)
  │     → returns 1 to height(1)
  └── height(3)
        ├── height(4)
        │     ├── height(NULL) → returns 0
        │     └── height(NULL) → returns 0
        │     → returns 1
        └── height(5)
              ├── height(NULL) → returns 0
              └── height(NULL) → returns 0
              → returns 1
        → returns max(1,1)+1 = 2
→ Final return from height(1): max(1,2)+1 = 3
*/