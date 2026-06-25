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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }
        q.push({root,{0,0}});

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* front=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            m[hd][lvl].push_back(front->val);

            if(front->left){
                q.push({front->left,{hd-1,lvl+1}});
            }
            if(front->right){
                q.push({front->right,{hd+1,lvl+1}});
            }
        }

        for(auto i:m){
            vector<int> level;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end()); // sort only same row & column
                for(auto k:j.second){
                    level.push_back(k);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};