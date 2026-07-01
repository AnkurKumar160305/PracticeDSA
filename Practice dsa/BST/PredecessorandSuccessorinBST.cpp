/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode* temp=root;
    int succ=-1;
    int pred=-1;
    while(temp!=NULL && temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }
    }

    if(temp==NULL){
        return {pred,succ};
    }

    //pred and succ
    TreeNode* leftTree=temp->left;

    //pred
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    //succ
    TreeNode* rightTree=temp->right;

    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

    return {pred,succ};
}