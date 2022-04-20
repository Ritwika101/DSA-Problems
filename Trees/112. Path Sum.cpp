bool solve(TreeNode* root, int target, int& sum, bool& flag){
        if(!root)
            return false;
        if(!root->left && !root->right){
            sum+=root->val;
            if(sum==target)
                flag=true;
            sum-=root->val;
            if(flag)
                return true;
        }
        sum+=root->val;
        if(solve(root->left,target,sum,flag))
            return true;
        if(solve(root->right,target,sum,flag))
            return true;
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>output;
        int sum=0;
        bool flag=false;
        return solve(root,targetSum,sum,flag);
        
    }
