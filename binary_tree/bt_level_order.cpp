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


void buildTreeLevelOrder(Node* &root) {
    queue<Node*> q;
    int data;
    cout<<"Enter data for root node:"<<endl;
    cin >> data;
    if(data == -1)
        return;
    root = new Node(data);
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left node of :"<<temp->data<<endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);   
        }
        
        cout<<"Enter right node of :"<<temp->data<<endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);   
        }
    }
    
}

void preOrderTraversal(Node * root) {
    if(root == NULL) {
        return;
    } else {
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    buildTreeLevelOrder(root);
    
    preOrderTraversal(root);
    return 0;
}