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

void calcPointers(Node *root, Node *&first, Node *&mid, Node *&last, Node *&prev){
    if(root == NULL){
        return ;
    }

    calcPointers(root->left, first, mid, last, prev);

    // If the asscending property is violated
    // for the first time.
    if(prev && root->data < prev->data){
        if(!first){
            first = prev;
            mid = root;
        }
        else{
            last = root;
        }
    }
    prev = root;

    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node *root){
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, first, mid, last, prev);

    // case 1 If the swapped nodes are not adjacent.
    if(first && last){
        swap((first->data), (last->data));
    }
    // case 2 If the swapped nodes are adjacent.
    else if(first && mid){
        swap((first->data), (mid->data));
    }

}

int main()
{
    Node *root = new Node(1);
    Node *sub1 = new Node(2);
    Node *sub2 = new Node(3);

    root->left = sub2;
    sub2->right = sub1;



    return 0;
}