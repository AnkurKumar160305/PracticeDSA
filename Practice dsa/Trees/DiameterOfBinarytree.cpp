class Solution {
    int height(Node* root) {
        // code here
        if(root==NULL){
            return -1;
        }
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
  public:
    int diameter(Node* root) {
        // code here
        if(root==NULL){
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+2;
        int ans=max(op1,max(op2,op3));
        return ans;
        
    }
};


// Optimized approach
class Solution {
  public:
  pair<int,int> diameterFast(Node* root){
        if(root==NULL){
           return {0,0};
        }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
  }
    int diameter(Node* root) {
        // code here
       return diameterFast(root).first;
        
    }
};