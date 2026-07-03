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


//TLE is occuring in this code because we are checking for every node whether it is a valid BST or not and then calculating the sum of that subtree. This results in a time complexity of O(n^2) in the worst case. 
class Solution {
    int sumTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        return root->val + sumTree(root->left) + sumTree(root->right);
    }
    bool isValidBST(TreeNode* root,long long mini,long long maxi){
        if(root==NULL){
            return true;
        }
        if(root->val>mini && root->val<maxi){
            return isValidBST(root->left,mini,root->val) && 
            isValidBST(root->right,root->val,maxi);
        }else{
            return false;
        }
    }
    void inorder(TreeNode* root,int& ans) {
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        if(isValidBST(root,LLONG_MIN, LLONG_MAX)){
            ans=max(ans,sumTree(root));
        }
        inorder(root->right,ans);
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        inorder(root,ans);
        return ans;
    }
};