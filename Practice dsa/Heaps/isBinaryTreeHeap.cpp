/*
class Node {
   public:
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
    
    int countNodes(Node* tree){
        if(tree==NULL){
            return 0;
        }
        int ans=1+countNodes(tree->left)+countNodes(tree->right);
        return ans;
    }
    
    bool isMaxorder(Node* tree){
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        if(tree->left!=NULL && tree->right==NULL){
            return tree->data>tree->left->data;
        }
        if(tree->left!=NULL && tree->right!=NULL){
            return tree->data>tree->left->data && tree->data>tree->right->data && 
            isMaxorder(tree->left) && isMaxorder(tree->right);
        }
    }
    
    bool isCBT(Node* tree,int i,int nodes){
        if(tree==NULL){
            return true;
        }
        if(i>=nodes){
            return false;
        }else{
            bool left=isCBT(tree->left,2*i+1,nodes);
            bool right=isCBT(tree->right,2*i+2,nodes);
            return left && right;
        }
    }
  public:
    bool isHeap(Node* tree) {
        // code here
        int index=0;
        int totalnodes=countNodes(tree);
        if(isCBT(tree,index,totalnodes) && isMaxorder(tree)){
            return true;
        }
        return false;
        
    }
};