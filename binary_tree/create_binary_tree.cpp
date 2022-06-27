#include<iostream>
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
    cout<<"Enter the data"<<endl;
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

int main() {
    Node* root = NULL;
    root = buildTree(root);
    cout<<"Tree created with root: "<<root->data;
    return 0;
}