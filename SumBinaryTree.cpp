// Check If a Binary Tree is a Sum Tree or not.

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

int findSum(Node *root){
	if(root == NULL){
		return 0;
	}
	int ans1 = findSum(root->left);
	int ans2 = findSum(root->right);
		
	// This condition will execute when pehle hi hme root->data != ans1+ans2 ki condition milgayi
	if(ans1 == -1 || ans2 == -1){
		return -1;
	}
	// if the currNode is leaf then return the same node data.
	else if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	// else check the required condition.
	else{
		if(root->data == (ans1+ans2)){
			return root->data+ans1+ans2;
		}
		else{
			return -1;
		}
	}
}

bool isSumTree(Node *root){
    int ans = findSum(root);
		
	if(ans != -1){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
    Node *root = new Node(44);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(13);
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

    if(isSumTree(root)){
        cout<<"Given Binary Tree is a sum tree."<<endl;
    }
    else{
        cout<<"Given Binary Tree is not a sum tree."<<endl;
    }
    return 0;
}