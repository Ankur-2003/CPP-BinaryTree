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

void sumNumbers(Node *root, int sum, vector<int> &ans){

    if(root == NULL){
        ans.push_back(sum);
        return ;
    }

    sum = sum*10 + root->data;
    // sumNumbers(root->left, sum, ans);
    // sumNumbers(root->right, sum, ans);
    if(root->left && root->right){
        sumNumbers(root->left, sum, ans);
        sumNumbers(root->right, sum, ans);
    }
    else if(!root->left && !root->right){
        sumNumbers(root->left, sum, ans);
    }
    else if(root->left){
        sumNumbers(root->left, sum, ans);
    }
    else if(root->right){
        sumNumbers(root->right, sum, ans);
    }
    sum = (sum-root->data)/10;
}

int main()
{
    Node *root = new Node(4);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(0);
    Node *sub3 = new Node(5);
    Node *sub4 = new Node(1);

    root->left = sub1;
    root->right = sub2;

    sub1->left = sub3;
    sub1->right = sub4;

    int sum=0;
    vector<int> v;

    sumNumbers(root, sum, v);
    for(auto itr:v){
        cout<<itr<<" ";
    }
    return 0;
}