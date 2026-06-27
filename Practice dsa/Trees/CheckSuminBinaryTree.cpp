bool isSumProperty(Node *root) {
        // code here
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
    
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
    
        return (left + right == root->data)
            && isSumProperty(root->left)
            && isSumProperty(root->right);
    }