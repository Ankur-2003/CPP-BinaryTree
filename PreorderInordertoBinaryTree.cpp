// We will be given Preorder and Inorder Traversal of a Binary Tree, and our task is to build corresponding Binary Tree.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int search(vector<int> inorder, int start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return start-1;
}

Node *constructBST(vector<int> preorder, int &ind, vector<int> inorder, int start, int end){

    if(start > end){
        return NULL;
    }

    int curr = preorder[ind];
    ind++;
    Node *root = new Node(curr);
    int mid = search(inorder, start+1, end, curr);
    root->left = constructBST(preorder, ind, inorder, start, mid-1);
    root->right = constructBST(preorder, ind, inorder, mid+1, end);

    return root;
}

void preorder1(Node *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder1(root->left);
    preorder1(root->right);
}

int main()
{
    vector<int> preorder = {2,4,7,8,5,6};
    vector<int> inorder = {7,4,8,2,5,6};

    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};
    int ind = 0;
    Node *root = constructBST(preorder, ind, inorder, 0, inorder.size()-1);
    preorder1(root);
    return 0;
}