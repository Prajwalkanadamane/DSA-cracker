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

void inorder(Node* root, vector<int>& temp){
   
    if (root == NULL){
        return;
    }
    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}

Node* BuildBSTfromSorted(vector<int>& arr, int st, int end){

    if (st>end) return NULL;

    int mid = st + (end-st)/2;

    Node* root = new Node(arr[mid]);

    root->left = BuildBSTfromSorted(arr, st, mid-1);
    root->right = BuildBSTfromSorted(arr, mid+1, end);

    return root;
}

Node* merge(Node* root1, Node* root2){

    vector<int> finalVec;

    vector<int> firstVec;
    vector<int> secondVec;

    inorder(root1, firstVec);
    inorder(root2, secondVec);

    int i =0, j=0;

    while(i<firstVec.size() && j<secondVec.size()){
        if (firstVec[i] < secondVec[j]){
            finalVec.push_back(firstVec[i++]);
        }else{
            finalVec.push_back(secondVec[j++]);           
        }
    }

    while(i < firstVec.size()){
        finalVec.push_back(firstVec[i++]);
    }

    while(j < secondVec.size()){
        finalVec.push_back(secondVec[j++]);
    }

    return BuildBSTfromSorted(finalVec, 0, finalVec.size()-1);

}

int main(){
    vector<int> vec1 = {8, 2, 1, 10};
    vector<int> vec2 = {5, 3, 0};

    Node* root1 = builBST(vec1);
    Node* root2 = builBST(vec2);

    Node* root = merge(root1, root2);
    vector<int> ans;

    inorder(root, ans);

    for (auto elem : ans){
        cout << elem << " ";
    }


    cout << endl;
    return 0;
}
