#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int inorder(BinaryTreeNode<int>* root,int k,int& cnt){
    if(root==NULL){
        return -1;
    }
    int left = inorder(root->left, k, cnt);
    if(left != -1)
        return left;

    cnt++;
    if(cnt == k)
        return root->data;

    return inorder(root->right, k, cnt);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int cnt=0;
    return inorder(root,k,cnt);
}



//solve this using morris traversal