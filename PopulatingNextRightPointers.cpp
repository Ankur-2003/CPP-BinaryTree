// In this problem we had given a Perfect Binary Tree and target was to populate the next pointer of each node to it's next right node and if there is no right node then next pointer should be set to NULL.

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

// This approach has Time Complexity and Space Complexity ans O(n).--> (for queue, and traversing each and every node.)
// Node *connectNextToRight(Node *root){
//     if(root == NULL){
//         return NULL;
//     }

//     queue<pair<int, Node*>> q;
//     q.push({0, root});
//     int prev = -1;
//     Node *prevNode = NULL;

//     while(!q.empty()){
//         int key = q.front().first;
//         Node *temp = q.front().second;
//         q.pop();

//         if(prev == key){
//             prevNode->next = temp;
//         }

//         if(temp->left){
//             q.push({key+1, temp->left});
//         }
//         if(temp->right){
//             q.push({key+1, temp->right});
//         }
        
//         prev = key;
//         prevNode = temp;
//     }

//     return root;
// }

// Another iterative method with O(1) solution.
Node *connectNextToRight(Node *root){
    if(root == NULL){
        return NULL;
    }

    Node *prev = root;
    Node *curr;
    while(prev){
        curr = prev;
        while(curr && curr->left){
            curr->left->next = curr->right;

            if(curr->next){
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
        prev = prev->left;
    }

    return root;
}

void preorder(Node *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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

    // preorder(root);
    root = connectNextToRight(root);
    return 0;
}