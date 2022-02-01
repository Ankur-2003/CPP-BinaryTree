// We will be given a target sum and we need to find out whether there exists a path from root to leaf where sum of each node in path equals to targetSum.

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

bool hasPath(Node *root, int targetSum, int count){
    if(root == NULL){
        if(targetSum == 0 && count != 0){
            return true;
        }
        return false;
    }
        
    targetSum -= root->data;
    count++;
        
    if((root->left && root->right) || (!root->left && !root->right)){
        return hasPath(root->left, targetSum, count) || hasPath(root->right, targetSum, count);
    }
    else if(root->left){
        return hasPath(root->left, targetSum, count);
    }
    else if(root->right){
        return hasPath(root->right, targetSum, count);
    }
}

int main()
{
    // First Test Case.
    // Node *root = new Node(5);
    // Node *sub1 = new Node(4);
    // Node *sub2 = new Node(8);
    // Node *sub3 = new Node(11);
    // Node *sub4 = new Node(13);
    // Node *sub5 = new Node(4);
    // Node *sub6 = new Node(7);
    // Node *sub7 = new Node(2);
    // Node *sub8 = new Node(1);

    // root->left = sub1;
    // root->right = sub2;

    // sub1->left = sub3;

    // sub2->left = sub4;
    // sub2->right = sub5;

    // sub3->left = sub6;
    // sub3->right = sub7;

    // sub5->right = sub8;

    // int targetSum = 22;
    // int sum = 0;

    // Second Test Case.
    Node *root = new Node(1);
    Node *sub1 = new Node(2);
    Node *sub2 = new Node(3);

    root->left = sub1;
    root->right = sub2;

    int targetSum = 5;
    int sum = 0;

    if(hasPath(root, targetSum, sum)){
        cout<<"Path exists:"<<endl;
    }
    else{
        cout<<"Path does not exist:"<<endl;
    }
    return 0;
}