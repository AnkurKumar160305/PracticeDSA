// (n-k+1) will be largest element in BST. So we can use same logic as kth smallest element in BST.
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    
    int bfs(Node* root){
        if(root==NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            cnt++;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return cnt;
    }
    int solve(Node* root,int k,int& cnt,int n){
        if(root==NULL){
            return -1;
        }
        int left=solve(root->left,k,cnt,n);
        if(left!=-1){
            return left;
        }
        cnt++;
        if(cnt==n-k+1){
            return root->data;
        }
        return solve(root->right,k,cnt,n);
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int cnt=0;
        int n=bfs(root);
        return solve(root,k,cnt,n);
    }
};











//using inorder traversal
class Solution {
    void inorder(Node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        return ans[n-k];
    }
};