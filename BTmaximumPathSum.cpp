// We will be given a Binary Tree and we need to find a path with maximum sum.

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

// Strategy.
/*  Compute
    1. Node Value.
    2. Max Path through left child + Node Value.
    3. Max Path through right child + Node Value.
    4. Max Path through left child + Max Path through right child + Node Value.
*/

int maxPathSum(Node *root, int &ans){

    if(root == NULL){
        return 0;
    }

    int left = maxPathSum(root->left, ans);
    int right = maxPathSum(root->right, ans);

    int NodeMax = max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));

    ans = max(ans, NodeMax);
    int singlePathSum = max(root->data, max(root->data+left, root->data+right));
    return singlePathSum;
}

void preorder(Node *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(-10);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(20);
    Node *sub3 = new Node(15);
    Node *sub4 = new Node(7);

    root->left = sub1;
    root->right = sub2;

    sub2->left = sub3;
    sub2->right = sub4;

    int PathSum = 0;

    int ans = maxPathSum(root, PathSum);
    cout<<PathSum;
    return 0;
}