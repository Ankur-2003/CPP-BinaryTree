// We have to find the level order traversal of a Binary Tree in different way.
/*
        3
       / \
      9   20
         /  \
        15   7

    Level Order Traversal should be in the form --> [[15, 7], [9, 20], [3]]; 
*/


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

vector<vector<int>> LevelOrderTraversal2(Node *root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }

    queue<pair<int, Node*>> q;
    q.push({1, root});
    vector<int> temp_v;
    int prev = 1;

    while(!q.empty()){
        int key = q.front().first;
        Node *temp = q.front().second;
        q.pop();

        if(prev != key){
            ans.push_back(temp_v);
            temp_v.clear();
        }

        temp_v.push_back(temp->data);
        if(temp->left){
            q.push({key+1, temp->left});
        }
        if(temp->right){
            q.push({key+1, temp->right});
        }
        prev = key;
    }

    ans.push_back(temp_v);
    temp_v.clear();

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Node *root = new Node(3);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(20);
    Node *sub3 = new Node(15);
    Node *sub4 = new Node(7);

    root->left = sub1;
    root->right = sub2;

    sub2->left = sub3;
    sub2->right = sub4;

    auto ans = LevelOrderTraversal2(root);

    cout<<ans[0][1];
    return 0;
}