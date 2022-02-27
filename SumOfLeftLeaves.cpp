// Given a Binary Tree and we have to find the sum of all left leaf nodes.

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

int sumOfLeftLeaves(Node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int sum=0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->right){
            q.push(temp->right);
        }
        temp = temp->left;
        while(temp){
            if(temp->right){
                q.push(temp->right);
            }
            else if(temp->left == NULL && temp->right == NULL){
                sum += temp->data;
            }
            temp = temp->left;
        }
    }

    return sum;
}

int main()
{
    Node *root = new Node(3);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(20);
    Node *sub3 = new Node(15);
    Node *sub4 = new Node(7);

    root->left = sub1;
    root->right = sub2;
    sub2->left = sub3;
    sub2->right = sub4;

    int ans = sumOfLeftLeaves(root);
    cout<<ans;
    return 0;
}