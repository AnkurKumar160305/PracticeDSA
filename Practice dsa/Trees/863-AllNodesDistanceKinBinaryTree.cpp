/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track ,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                parent_track[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent_track[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curr_lvl=0;

        while(!q.empty()){
            //Second bfs to fo upto k level from target node and using hashmap info
            int size=q.size();
            if(curr_lvl++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    q.push(current->left);
                    vis[current->left]=true;
                }
                if(current->right && !vis[current->right]){
                    q.push(current->right);
                    vis[current->right]=true;
                }
                if(parent_track[current] && !vis[parent_track[current]]){
                    q.push(parent_track[current]);
                    vis[parent_track[current]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            res.push_back(current->val);
        }
        return res;
    }
};