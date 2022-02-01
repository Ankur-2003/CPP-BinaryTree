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

vector<vector<int>> LevelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
        
    queue<pair<int, Node*>> q;
    q.push({1, root});
    int prev = 1;
    vector<int> temp_v;
        
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
        
    if(!temp_v.empty()){
        ans.push_back(temp_v);
        temp_v.clear();
    }
        
    return ans;
}   

int main()
{
    Node *root = new Node(3);
    Node *sub1 = new Node(9);
    Node *sub2 = new Node(20);
    Node *sub3 = new Node(11);
    Node *sub4 = new Node(12);
    Node *sub5 = new Node(13);
    Node *sub6 = new Node(14);
    Node *sub7 = new Node(15);
    Node *sub8 = new Node(16);

    root->left = sub1;
    root->right = sub2;

    sub1->left = sub3;
    sub2->right = sub4;

    sub3->left = sub5;
    sub3->right = sub6;

    sub4->left = sub7;
    sub4->right = sub8;

    auto ans = zigzagLevelOrder(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}