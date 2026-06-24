/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    void createMapping(vector<int> inorder,map<int,int>& nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    Node* solve(vector<int> inorder,vector<int> preorder,int& index,int inorderstart,int inorderend,int n,map<int,int>& nodeToIndex){
        if(index>=n || inorderstart>inorderend){
            return NULL;
        }
        int element=preorder[index++];
        Node* root=new Node(element);
        int pos=nodeToIndex[element];
        
        //In preorder we build left subtree first then right subtree
        root->left=solve(inorder,preorder,index,inorderstart,pos-1,n,nodeToIndex);
        root->right=solve(inorder,preorder,index,pos+1,inorderend,n,nodeToIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n=inorder.size();
        int preOrderIndex=0;
        map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
        
    }
};