/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
    void inorder(Node* root,vector<int>& in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    void postorderFill(Node*& root,vector<int>& in,int& index){
        if(root==NULL){
            return;
        }
        postorderFill(root->left,in,index);
        postorderFill(root->right,in,index);
        root->data=in[index++];
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> in;
        inorder(root,in);
        int index=0;
        postorderFill(root,in,index);
    }
};