#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// This function is used to serialize the given Binary Tree int string format.
void TreetoString(Node *root, string &str){

    if(root == NULL){
        char ch1 = '#';
        char ch2 = ',';
        str = str+ch1+ch2;
        return ;
    }

    str.append(to_string(root->data) + ',');
    TreetoString(root->left, str);
    TreetoString(root->right, str);
}

// 1,2,4,#,#,5,#,#,3,6,#,#,7,#,#
// Now we want to Deserialize the Binary Tree to string.
Node* StringtoTree(vector<string> v, int &ind){

    if(v[ind] == "#" && ind != v.size()){
        ind++;
        return NULL;
    }
    
    // Node *root = new Node(stoi(v[ind]));
    int temp = stoi(v[ind]);
    Node *root = new Node(temp);
    ind++;
    root->left = StringtoTree(v, ind);
    root->right = StringtoTree(v, ind);
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

    string ans = "";
    // Serializing the Tree. Converting the Binary Tree to String.
    TreetoString(root, ans);
    cout<<ans<<endl;

    // Deserializing the Tree. Converting the serialized String to Binary Tree.
    vector<string> v;
    string temp = "";

    // First removing ',' from the ans and making array of nodeInt and null.
    for(int i=0;i<ans.length();i++){
        if(ans[i] == ','){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp += ans[i];
        }
    }
    int ind=0;
    root = StringtoTree(v, ind);

    // Preorder Traversal to just check the tree.
    preorder(root);
    return 0;
}