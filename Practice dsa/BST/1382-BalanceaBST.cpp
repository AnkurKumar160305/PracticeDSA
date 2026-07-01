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
    void inorder(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    TreeNode* inordertoBst(int s,int e,vector<int>& ans){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=inordertoBst(s,mid-1,ans);
        root->right=inordertoBst(mid+1,e,ans);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        return inordertoBst(0,ans.size()-1,ans);
    }
};