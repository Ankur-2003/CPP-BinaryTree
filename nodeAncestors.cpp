// This problem is to find the ancestors of a given node in a binary tree.

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

Node *printAncestors(Node *root, Node *node){

    if(root == NULL){
        return NULL;
    }

    if(root->data == node->data){
        cout<<root->data<<" ";
        return root;
    }
    Node *left = printAncestors(root->left, node);
    Node *right = printAncestors(root->right, node);

    if(left || right){
        cout<<root->data<<" ";
    }
    if(left){
        return left;
    }
    if(right){
        return right;
    }
    return NULL;
}

int main()
{
    Node *root = new Node(1);
    Node *sub1 = new Node(2);
    Node *sub2 = new Node(3);
    Node *sub3 = new Node(4);
    Node *sub4 = new Node(5);
    Node *sub5 = new Node(6);
    Node *sub6 = new Node(7);

    root->left = sub1;
    root->right = sub2;

    sub1->left = sub3;
    sub1->right = sub4;

    sub2->left = sub5;
    sub2->right = sub6;

    root = printAncestors(root, sub3);
    return 0;
}