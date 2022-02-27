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

vector<int> RightView(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    queue<pair<int, Node*>> q;
    map<int, vector<int>> mp;
    q.push({1, root});

    while(!q.empty()){
        int key = q.front().first;
        Node *temp = q.front().second;
        q.pop();

        if(temp->left){
            q.push({key+1, temp->left});
        }
        if(temp->right){
            q.push({key+1, temp->right});
        }

        mp[key].push_back(temp->data);
    }

    for(auto itr:mp){
        auto v = itr.second;
        int temp = v.back();
        ans.push_back(temp);
    }
    
    return ans;
}

int main()
{
    Node *root = new Node(1);
    Node *sub1 = new Node(2);
    Node *sub2 = new Node(3);
    Node *sub3 = new Node(4);
    Node *sub4 = new Node(5);

    root->left = sub1;
    root->right = sub2;

    sub1->right = sub4;
    sub2->right = sub3;

    auto ans = RightView(root);
    for(auto itr:ans){
        cout<<itr<<" ";
    }
    return 0;
}