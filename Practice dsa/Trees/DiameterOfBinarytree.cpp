/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    int diameter(Node* root) {
        // code here
        if(root==NULL){
            return 0;
        }
        int left=diameter(root->left);
        int right=diameter(root->right);
        int mix=height(root->left)+height(root->right);
        int ans=max(left,max(right,mix));
        return ans;
    }
};

// Optimized approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
  public:
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};