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
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        // code here
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL || r2==NULL){
            return false;
        }
        bool left=isMirror(r1->left,r2->right);
        bool right=isMirror(r1->right,r2->left);
        bool val=r1->val==r2->val;
        
        return left && right && val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return isMirror(root->left,root->right);
    }
};