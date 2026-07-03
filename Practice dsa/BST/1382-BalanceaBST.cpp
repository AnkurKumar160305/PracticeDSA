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




//Optimal
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
    struct NodeValue {
        bool isBST;
        int sum;
        int mini;
        int maxi;

        NodeValue(bool bst, int s, int mn, int mx) {
            isBST = bst;
            sum = s;
            mini = mn;
            maxi = mx;
        }
    };

    int ans = 0;

    NodeValue solve(TreeNode* root) {

        if (root == NULL) {
            return NodeValue(true, 0, INT_MAX, INT_MIN);
        }

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        if (left.isBST &&
            right.isBST &&
            left.maxi < root->val &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return NodeValue(
                true,
                currSum,
                min(root->val, left.mini),
                max(root->val, right.maxi)
            );
        }

        return NodeValue(false, 0, INT_MIN, INT_MAX);
    }

public:
    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};