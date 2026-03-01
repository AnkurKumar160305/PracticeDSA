/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
    pair<bool,int> isSumTreeFast(Node* root){
        if(root==NULL){
            return {true,0};
        }
        //leaf node
        if(root->left==NULL && root->right==NULL){
            return {true,root->data};
        }
        auto leftAns=isSumTreeFast(root->left);
        auto rightAns=isSumTreeFast(root->right);
        
        bool left=leftAns.first;
        bool right=rightAns.first;
        bool sum=leftAns.second+rightAns.second==root->data;
        
        return {left && right && sum,2*root->data};
    }
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreeFast(root).first;
    }
};