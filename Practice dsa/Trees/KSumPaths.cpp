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

//  437. Path Sum III
class Solution {
    void solve(TreeNode* root,int targetSum,int &cnt,vector<int> &path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        solve(root->left,targetSum,cnt,path);
        solve(root->right,targetSum,cnt,path);

        int size=path.size();
        long long sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum){
                cnt++;
            }
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int cnt=0;
        solve(root,targetSum,cnt,path);
        return cnt;
    }
};