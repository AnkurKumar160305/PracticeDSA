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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);

        return  l && r && p->val==q->val;
    }

    bool isSubtree(TreeNode* root,TreeNode* subRoot){
        if(root==NULL){
            return false;
        }
        if(root->val==subRoot->val && isSameTree(root,subRoot)){
            return true;
        }
        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        return l || r;

    }
};