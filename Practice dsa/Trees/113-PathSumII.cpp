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
    void solve(TreeNode* root,int targetSum,int sum,vector<int>& path,vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==targetSum){
            ans.push_back(path);
        }else{
            solve(root->left,targetSum,sum,path,ans);
            solve(root->right,targetSum,sum,path,ans);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> path;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};