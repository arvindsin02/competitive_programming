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

pair<bool,int> balancedTreeFast(Node* root) {
    if(root == NULL) {
        return make_pair(true, 0);
    } else {
        pair<bool,int> left = balancedTreeFast(root->left);
        pair<bool,int> right = balancedTreeFast(root->right);
        
        bool h = abs(left.second - right.second) <= 1;
        int height = max(left.second, right.second)+1;
        
        if(left.first && right.first && h) {
            return make_pair(true, height);
        } else {
            return make_pair(false, height);
        }
    }
}

bool balancedTreeSlow(Node* root) {
    if(root == NULL){
        return true;
    } else {
        bool left = balancedTreeSlow(root->left);
        bool right = balancedTreeSlow(root->right);
        
        int hl = height(root->left);
        int hr = height(root->right);
        
        bool height = abs(hl-hr) <= 1;
        
        if(left && right && height) {
            return true;
        } else {
            return false;
        }
    }
}

bool balancedTree(Node* root) {
    pair<bool,int> p = balancedTreeFast(root);
    return p.first;
}


int main() {
    Node* root = NULL;
    root = buildTreeLevelOrder(root);
    cout<<endl;
    cout<<balancedTree(root);
    return 0;
}