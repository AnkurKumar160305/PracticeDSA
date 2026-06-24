/* Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
    void createMapping(vector<int> inorder,map<int,int>& nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    Node* solve(vector<int> inorder,vector<int> postorder,int& index,int inorderstart,int inorderend,int n,map<int,int>& nodeToIndex){
        if(index<0 || inorderstart>inorderend){
            return NULL;
        }
        int element=postorder[index--];
        Node* root=new Node(element);
        int pos=nodeToIndex[element];
        
        //in PostOrder we build right subtree first then left subtree
        root->right=solve(inorder,postorder,index,pos+1,inorderend,n,nodeToIndex);
        root->left=solve(inorder,postorder,index,inorderstart,pos-1,n,nodeToIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n=inorder.size();
        int postOrderIndex=n-1;
        map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        Node* ans=solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};