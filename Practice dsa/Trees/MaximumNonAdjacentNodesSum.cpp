/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    pair<int,int> solve(Node* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int> res;
        
        res.first=root->data+left.second+right.second;
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
    }
  public:
    int getMaxSum(Node *root) {
        // code here
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
        
    }
};