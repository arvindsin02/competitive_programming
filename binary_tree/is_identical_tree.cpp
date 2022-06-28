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


int height(Node* root) {
    if(root == NULL) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right)+1;
    }
}

bool indenticalTree(Node* r1, Node* r2) {
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
    if(r1 != NULL && r2 == NULL) {
        return false;
    }
    if(r1->data != r2->data) {
        return false;
    }
    
    bool left = indenticalTree(r1->left, r2->left);
    bool right = indenticalTree(r1->right, r2->right);
    
    if(left && right) {
        return true;
    } else {
        return false;
    }

}


int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = buildTreeLevelOrder(root1);
    cout<<endl<<"Tree1 created"<<endl;
    root2 = buildTreeLevelOrder(root2);
    cout<<"Tree2 Created"<<endl;
    cout<<indenticalTree(root1, root2);
    return 0;
}