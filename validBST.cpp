// Check if a given BST is valid or not. Find out InOrder Traversal check if it is sorted or not. If sorted the valid else not.

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

void inorder(Node* root, vector<int> &v){
    if(root == NULL){
        return ;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool isvalidBST(Node *root){
    vector<int> v;
    inorder(root, v);
        
    int flag = 0;
    for(int i=0;i<v.size()-1;i++){
        if(v[i] < v[i+1]){
            continue;
        }
        else{
            flag = 1;
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    // Test case 1.
    Node *root = new Node(5);
    Node *sub1 = new Node(1);
    Node *sub2 = new Node(4);
    Node *sub3 = new Node(3);
    Node *sub4 = new Node(6);
    root->left = sub1;
    root->right = sub2;

    sub2->left = sub3;
    sub2->right = sub4;

    // Test Case 2.
    // Node *root = new Node(5);
    // Node *sub1 = new Node(4);
    // Node *sub2 = new Node(3);
    // Node *sub3 = new Node(6);
    // Node *sub4 = new Node(9);
    // Node *sub5 = new Node(8);
    // Node *sub6 = new Node(10);
    // root->left = sub1;
    // sub1->left = sub2;

    // root->right = sub3;
    // sub3->right = sub4;

    // sub4->left = sub5;
    // sub4->right = sub6;



    if(isvalidBST(root)){
        cout<<"Given Binary Tree is valid Binary Tree."<<endl;
    }
    else{
        cout<<"Given Binary Tree is not a valid Binary Tree."<<endl;
    }
    return 0;
}