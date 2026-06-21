class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
                if(i==0){
                    ans.push_back(temp->data);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return ans;
    }
};



/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    void solve(Node* root,vector<int>& ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};