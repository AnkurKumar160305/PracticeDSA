// struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

vector<int> zigZagTraversal(TreeNode* root) {
    // add your code here
    vector<int> ans;
    if(!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            int index=leftToright? i :(size-1-i);
            level[index]=node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        for(int val:level){
            ans.push_back(val);
        }
        leftToright=!leftToright;
    }
    return ans;
}