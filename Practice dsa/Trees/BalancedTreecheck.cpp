class Solution {
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
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL){
            return true;
        }
        int left=isBalanced(root->left);
        int right=isBalanced(root->right);
        int diff=abs(height(root->right)-height(root->left));
        return left && right && diff<=1;
    }
};

// Optimized approach
class Solution {
    pair<bool,int> solve(Node* root){
        if(root==NULL){
            return {true,0};
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        bool leftAns=left.first;
        bool rightAns=right.first;
        
        bool diff=abs(left.second-right.second)<=1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        return {leftAns && rightAns && diff,ans.second};
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        return solve(root).first;
    }
};