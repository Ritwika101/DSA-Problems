bool solve(TreeNode* root, int key){
        if(!root)
            return true;
        if(root->val!=key)
            return false;
        return (solve(root->left, key) && solve(root->right,key));
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        return solve(root,root->val);
    }
