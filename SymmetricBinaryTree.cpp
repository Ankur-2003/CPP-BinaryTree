// In this code we want to check if given binary tree is Symmetric/Mirror Image or not.

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

bool check(Node *x, Node *y){
    // Base Case.
    if(x == NULL && y == NULL){
        return true;
    }
    // Another Base Case.
    if(x == NULL || y == NULL){
        return false;
    }

    if(x->data != y->data){
        return false;
    }

    auto ans1 = check(x->left, y->right);
    auto ans2 = check(x->right, y->left);

    if(ans1 == false || ans2 == false){
        return false;
    }
    return true;
}

bool isSymmetric(Node *root){
    if(root == NULL){
        return true;
    }
    if(check(root->left, root->right)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    Node *root = new Node(1);
    Node *sub1 = new Node(2);
    Node *sub2 = new Node(2);
    Node *sub3 = new Node(3);
    Node *sub4 = new Node(3);
    // Node *sub5 = new Node(4);
    // Node *sub6 = new Node(3);

    root->left = sub1;
    root->right = sub2;

    // sub1->left = sub3;
    sub1->right = sub3;

    // sub2->left = sub5;
    sub2->right = sub4;

    if(isSymmetric(root)){
        cout<<"Binary Tree is symmetric:"<<endl;
    }
    else{
        cout<<"Binary Tree is not symmetric:"<<endl;
    }
    return 0;
}