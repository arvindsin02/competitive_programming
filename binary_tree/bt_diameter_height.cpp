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


Node*  buildTreeLevelOrder(Node* &root) {
    queue<Node*> q;
    int data;
    cout<<"Enter data for root node:"<<endl;
    cin >> data;
    if(data == -1)
        return NULL;
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
    
    return root;
    
}


void levelOrderTraversal(Node* &root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);   
        }   
        if(temp->right != NULL) {
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


int height(Node* root) {
    if(root == NULL) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right)+1;
    }
}

int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int dl = diameter(root->left);
    int dr = diameter(root->right);
    
    int h = height(root->left)+height(root->right)+1;
    
    return max(max(dl,dr),h);
}

int main() {
    Node* root = NULL;
    root = buildTreeLevelOrder(root);
    //levelOrderTraversal(root);
    cout<<endl;
    //preOrderTraversal(root);
    cout<<diameter(root);
    return 0;
}