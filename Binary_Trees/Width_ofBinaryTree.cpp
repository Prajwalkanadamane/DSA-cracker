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

void preOrderx(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderx(root->left);
    preOrderx(root->right);

}

int max_widthOf_binaryTree(Node* root){
    queue<pair<Node*, unsigned long long>> q;

    q.push({root, 0});
    int maxWidth = 0;

    while(q.size() > 0){
        int currLvlSize = q.size();
        unsigned long long startIdx = q.front().second;
        unsigned long long endIdx = q.back().second;

        maxWidth = max(maxWidth, (int) (endIdx - startIdx + 1));

        for (int i=0; i<currLvlSize; i++){
            auto curr = q.front();

            q.pop();

            if (curr.first->left){
                q.push({curr.first->left, curr.second*2+1});
            }

            if (curr.first->right){
                q.push({curr.first->right, curr.second*2+2});
            }
        }
    }
    return maxWidth;
}

int main(){
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
    Node* root = buildTree(preorder);

    // preOrderx(root);
    int result = max_widthOf_binaryTree(root);

    cout << result << endl;

    return 0;
}