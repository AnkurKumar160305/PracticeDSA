/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    
    void findDig(Node* root,int pos,vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        ans[pos].push_back(root->data);
        findDig(root->left,pos+1,ans);
        findDig(root->right,pos,ans);
    }
    void find(Node* root,int pos,int& l){
        if(root==NULL){
            return;
        }
        l=max(pos,l);
        find(root->left,pos+1,l);
        find(root->right,pos,l);
    }
  public:
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;
        find(root,0,l);//left most diagonal
        
        vector<vector<int>> ans(l+1);
        findDig(root,0,ans);
        
        vector<int> temp;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                temp.push_back(ans[i][j]);
            }
        }
        
        return temp;
    }
};