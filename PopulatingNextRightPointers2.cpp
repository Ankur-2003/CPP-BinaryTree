// In this problem we had given a Binary Tree (Not necessarily perfect) and target was to populate the next pointer of each node to it's next right node and if there is no right node then next pointer should be set to NULL.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node *next;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->next = NULL;
        }
};

Node *connectNextToRight(Node *root){
    if(root == NULL){
        return NULL;
    }

    Node *prev = root;
    Node *curr;

    while(prev){
        curr = prev;
        while(curr && curr->left){
            if(curr->right){
                curr->left->next = curr->right;
            }
            if(curr->next){
                if(curr->right){
                    if(curr->next->left){
                        curr->right->next = curr->next->left;
                    }
                    else if(curr->next->right){
                        curr->right->next = curr->next->right;
                    }
                }
                else{
                    if(curr->next->left){
                        curr->left->next = curr->next->left;
                    }
                    else if(curr->next->right){
                        curr->left->next = curr->next->right;
                    }
                }
            }
            curr = curr->next;
        }
        prev = prev->left;
    }
    return root;
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

    // sub2->left = sub5;
    sub2->right = sub6;

    // preorder(root);
    root = connectNextToRight(root);
    cout<<root->left->left->next->next->data;
    return 0;
}