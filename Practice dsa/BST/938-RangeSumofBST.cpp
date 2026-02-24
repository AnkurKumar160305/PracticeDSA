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
    void preOrder(TreeNode* root, int low, int high,int &cnt){
        if(root==NULL){
            return;
        }
        if(root->val>=low && root->val<=high){
            cnt+=root->val;
        }
        preOrder(root->left,low,high,cnt);
        preOrder(root->right,low,high,cnt);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int cnt=0;
        preOrder(root,low,high,cnt);
        return cnt;
    }
};



//Optimal 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val 
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};