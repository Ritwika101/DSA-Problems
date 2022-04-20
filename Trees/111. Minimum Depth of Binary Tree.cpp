
void solve(TreeNode* root,int level, int& m){
        if(!root)
            return;
        if(!root->left && !root->right){
            m = min(m,level);
            return;
        }
        solve(root->left,level+1,m);
        solve(root->right,level+1,m);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int level=1;
        int m=INT_MAX;
        solve(root,level, m);
        return m;
    }
