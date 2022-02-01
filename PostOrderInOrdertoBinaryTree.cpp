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
            this->left = left;
            this->right = right;
        }
};

int search(vector<int> inorder, int start, int end, int data){
    for(int i=start;i<=end;i++){
        if(data == inorder[i]){
            return i;
        }
    }
    return start;
}

Node *constructBT(vector<int> postorder, int &ind, vector<int> inorder, int start, int end){

    if(start > end){
        return NULL;
    }

    int currdata = postorder[ind];
    ind--;

    Node *root = new Node(currdata);
    int mid = search(inorder, start, end, currdata);
    root->right = constructBT(postorder, ind, inorder, mid+1, end);
    root->left = constructBT(postorder, ind, inorder, start, mid-1);

    return root;
}

void postorderfun(Node *root){
    if(root == NULL){
        return ;
    }
    postorderfun(root->left);
    cout<<root->data<<" ";
    postorderfun(root->right);
}

int main()
{
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int ind = postorder.size()-1;
    Node *root = constructBT(postorder, ind, inorder, 0, inorder.size()-1);
    postorderfun(root);
    return 0;
}