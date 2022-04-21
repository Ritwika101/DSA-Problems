
void solve(TreeNode* root, int& sum, bool flag){
        if(!root)
            return;
        if(!root->left && !root->right && flag){
            sum+=root->val;
            return;
        }
        solve(root->left,sum,1);
        solve(root->right,sum,0);
        return;
            
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool flag=0;
        solve(root,sum,flag);
        return sum;
    }
