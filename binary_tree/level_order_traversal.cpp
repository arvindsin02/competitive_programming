#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree(Node* root) {
    int data;
    cin>>data;
    if(data == -1) 
        return NULL;
    root = new Node(data);
    
    cout<<"Enter left child of: "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter right child of: "<<data<<endl;
    root->right = buildTree(root->right);
  
    return root;
}

void levelOrderTraversal(Node* root) {
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;
    cout<<"Enter the root node:"<<endl;
    root = buildTree(root);
    cout<<"Tree created with root: "<<root->data<<endl;
    levelOrderTraversal(root);
    return 0;
}