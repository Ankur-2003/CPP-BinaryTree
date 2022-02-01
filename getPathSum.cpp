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

void getPathSum(Node *root, int targetSum, vector<int> temp){
    if(root == NULL){
        if(targetSum == 0){
            for(auto itr:temp){
                cout<<itr<<" ";
            }
        }
        return ;
    }
    targetSum -= root->data;
    temp.push_back(root->data);

    // Main Recursion Starts.
    if(root->left && root->right){
        getPathSum(root->left, targetSum, temp);
        getPathSum(root->right, targetSum, temp);
    }
    else if(!root->left && !root->right){
        getPathSum(root->left, targetSum, temp);
    }
    else if(root->left){
        getPathSum(root->left, targetSum, temp);
    }
    else if(root->right){
        getPathSum(root->right, targetSum, temp);
    }
}

int main()
{
    Node *root = new Node(5);
    Node *sub1 = new Node(4);
    Node *sub2 = new Node(8);
    Node *sub3 = new Node(11);
    Node *sub4 = new Node(13);
    Node *sub5 = new Node(4);
    Node *sub6 = new Node(7);
    Node *sub7 = new Node(2);
    Node *sub8 = new Node(1);
    Node *sub9 = new Node(5);

    root->left = sub1;
    root->right = sub2;

    sub1->left = sub3;

    sub2->left = sub4;
    sub2->right = sub5;

    sub3->left = sub6;
    sub3->right = sub7;

    sub5->left = sub9;
    sub5->right = sub8;

    // Node *root = new Node(1);
    // Node *sub1 = new Node(2);
    // root->left = sub1;

    int targetSum = 22;
    int sum = 0;
    vector<int> temp;
    vector<vector<int>> ans;

    getPathSum(root, targetSum, temp);
    return 0;
}