// Problem is just like BST from sorted Array. We will be given sorted Linked list instead, and we will be constructing the BST. The main thing to keep in mind is maintaining the pointers of list int construct function.

#include<bits/stdc++.h>
using namespace std;

// Linked list ADT.
class listNode{
    public:
        int data;
        listNode *next;
        
        listNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Binary Tree ADT
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void print(listNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

listNode* findMiddleNode(listNode* head){
    listNode* fast = head;
    listNode* slow = head;
    listNode* prev = NULL;

    while(fast && slow){
        fast = fast->next;
        if(fast){
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
    }

    return prev;
}

TreeNode* constructBST(listNode* head){

    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        TreeNode* root = new TreeNode(head->data);
        return root;
    }

    listNode* prev_to_mid = findMiddleNode(head);
    listNode* mid = prev_to_mid->next;
    prev_to_mid->next = NULL;

    listNode* head1 = head;
    listNode* head2 = NULL;
    if(mid->next){
        head2 = mid->next;
    }

    TreeNode* root = new TreeNode(mid->data);
    root->left = constructBST(head1);
    root->right = constructBST(head2);
    return root;
}

void preorder(TreeNode* root){
    if(root == NULL){
        return ;
    }  
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

int main()
{
    int n;
    cout<<"Enter size of list:";
    cin>>n;

    int data;
    cout<<"Enter element:";
    cin>>data;
    listNode* head = new listNode(data);
    listNode* temp = head;

    for(int i=1;i<n;i++){
        cout<<"Enter element:";
        cin>>data;
        temp->next = new listNode(data);
        temp = temp->next;
    }

    // print(head);
    TreeNode* root = constructBST(head);
    preorder(root);

    return 0;
}