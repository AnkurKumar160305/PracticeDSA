#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter the data for the left child of: "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for the right child of: "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            // we have completed one level
            cout<<endl;
            if(!q.empty()){// queue still has some nodes
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
    
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    node* root=NULL;
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
}