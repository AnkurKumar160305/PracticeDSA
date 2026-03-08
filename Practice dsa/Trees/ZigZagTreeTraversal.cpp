/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToright=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
        
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
                //insert or reverse insert
                int idx=leftToright?i:size-i-1;
                level[idx]=temp->data;
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            for(auto i:level){
                ans.push_back(i);
            }
            //direction change  
            leftToright=!leftToright;
        }
        return ans;
    }
};