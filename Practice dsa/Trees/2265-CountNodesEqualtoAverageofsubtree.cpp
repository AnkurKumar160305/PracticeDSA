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
    pair<int,int> solve(int& ans,TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        
        pair<int,int> left=solve(ans,root->left);
        pair<int,int> right=solve(ans,root->right);

        int sum=left.first+right.first+root->val;
        int cnt=left.second+right.second+1;

        if(root->val==sum/cnt){
            ans++;
        }

        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(ans,root);
        return ans;
    }
};