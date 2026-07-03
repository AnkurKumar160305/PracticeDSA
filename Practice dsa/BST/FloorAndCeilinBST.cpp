/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
    void solve(TreeNode* root,int& floorBST,int& ceilBST,int key){
        if(root==NULL){
            return;
        }
        if(root->data==key){
            floorBST=key;
            ceilBST=key;
        }else if(root->data<key){
            floorBST=root->data;
            solve(root->right,floorBST,ceilBST,key);
        }else{
            ceilBST=root->data;
            solve(root->left,floorBST,ceilBST,key);
        }
    }
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            int floorBST=-1,ceilBST=-1;
            solve(root,floorBST,ceilBST,key);
            return {floorBST,ceilBST};
		}
};