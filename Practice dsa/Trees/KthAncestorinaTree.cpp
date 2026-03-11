/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
    int solve(Node* root,int k,int node,vector<int> &path){
        if(root == NULL)
            return -1;

        path.push_back(root->data);

        if(root->data == node){
            
            int size = path.size();

            if(size - k - 1 >= 0)
                return path[size - k - 1];
            else
                return -1;
        }

        int left = solve(root->left, k, node, path);
        if(left != -1)
            return left;

        int right = solve(root->right, k, node, path);
        if(right != -1)
            return right;

        path.pop_back();

        return -1;
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        vector<int> path;
        return solve(root,k,node,path);
        
    }
};


//Optimal
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
    Node* solve(Node* root,int &k,int node){
        if(root == NULL){
            return NULL;
        }
        if(root->data==node){
            return root;
        }
        
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        if(leftAns!=NULL && rightAns==NULL){
            k--;
            if(k<=0){
                //answer locked
                k=INT_MAX;
                return root;
            }
            return leftAns;
        }
        if(leftAns==NULL && rightAns!=NULL){
            k--;
            if(k<=0){
                //answer locked
                k=INT_MAX;
                return root;
            }
            return rightAns;
        }
        return NULL;
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node* ans=solve(root,k,node);
        if(ans==NULL || ans->data==node){
            return -1;
        }else{
            return ans->data;
        }
        
    }
};
