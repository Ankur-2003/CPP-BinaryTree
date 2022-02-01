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

Node *BST(vector<int> v, int start, int end){
    Node *root = NULL;  
    if(start <= end){
        int mid = (start + end) / 2;
        root = new Node(v[mid]);
        root->left = BST(v, start, mid-1);
        root->right = BST(v, mid+1, end);
    }
    return root;
}

Node *formBST(vector<int> v){
    Node *root = BST(v, 0, v.size()-1);
    return root;
}

void preorder(Node *root){
    if(root == NULL){
        return; 
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> v = {-10, -3, 0, 5, 9};

    Node* root = formBST(v);
    // cout<<root->data;
    preorder(root);
    return 0;
}