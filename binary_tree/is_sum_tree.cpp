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


pair<bool,int> isSumTree(Node* root) {
    if(root == NULL) {
        return make_pair(true,0);
    } else {
        pair<bool,int> left = isSumTree(root->left);
        pair<bool,int> right = isSumTree(root->right);
        bool sumBool;
        if(root->left == NULL && root->right == NULL) {
            sumBool = true;
        } else {
            sumBool = (left.second+right.second) == root->data;   
        }
        int sum = left.second+right.second+root->data;
        if(left.first && right.first && sumBool) {
            return make_pair(true,sum);
        } else {
            return make_pair(false,sum);
        }
    }
}

bool isSumTreeUtil(Node* root) {
    pair<bool,int> p = isSumTree(root);
    return p.first;
}


int main() {
    Node* root = NULL;
    root = buildTreeLevelOrder(root);
    cout<<endl<<"Tree1 created"<<endl;
    cout<<isSumTreeUtil(root);
    return 0;
}