class Solution
{
    int height(Node *root)
    {
        // code here
        if (root == NULL)
        {
            return -1;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int diameter(Node *root)
    {
        // code here
        if (root == NULL)
        {
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 2;
        int ans = max(op1, max(op2, op3));
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
    pair<int,int> diameterFast(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto left=diameterFast(root->left);
        auto right=diameterFast(root->right);
        int h=max(left.second,right.second)+1;

        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;

        int dia=max(op1,max(op2,op3));
        return {dia,h};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};