// We do not have to use extra space, We have to construct a DLL inplace by changing left and right pointers of the Tree. Here left and right pointers of Binary Tree will act as prev and next pointers in DLL.

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

void createDLL(Node *root, Node *&head, Node *&prev){
    if(root == NULL){
        return ;
    }
    
    createDLL(root->left, head, prev);
    if(head == NULL){
        head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    createDLL(root->right, head, prev);
}

Node *BinaryToDLL(Node *root){
    
    Node *head = NULL;
    Node *prev = NULL;

    createDLL(root, head, prev);
    
    return head;
}

void PreOrder(Node *root){
    if(root == NULL){
        return ;
    }
    PreOrder(root->left);
    cout<<root->data<<" ";
    PreOrder(root->right);
}

void PrintDLL(Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(10);
    Node *sub1 = new Node(20);  
    Node *sub2 = new Node(30);  
    Node *sub3 = new Node(40);  
    Node *sub4 = new Node(60);

    root->left = sub1;
    root->right = sub2;

    sub1->left = sub3;
    sub1->right = sub4;

    Node *head = BinaryToDLL(root);
    // PreOrder(head);
    PrintDLL(head);
    return 0;
}