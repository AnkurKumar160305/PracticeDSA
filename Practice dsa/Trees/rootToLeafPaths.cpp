/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    void solve(Node* root,vector<int>& path,vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        path.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);    
        }else{
            solve(root->left,path,ans);
            solve(root->right,path,ans);
        }
        path.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,path,ans);
        return ans;
    }
};