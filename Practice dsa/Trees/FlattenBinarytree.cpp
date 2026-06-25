//using recursion
// Recursive Approach (Reverse Preorder)

// Traverse:

// Right -> Left -> Root

// Maintain a prev pointer to the previously processed node.

// Steps
// Flatten right subtree.
// Flatten left subtree.
// Connect current node to prev.
// Set left = NULL.
// Update prev = root.
class Solution {
    TreeNode* prev = NULL;

public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};



//Flatten Binary Tree to Linked List using Morris Traversal
class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};