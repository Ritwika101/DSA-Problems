void solve(TreeNode* root, int level, TreeNode* parent, vector<vector<int>>&info, int x, int y ){
        if(!root)
            return;
        if(root->val == x){
            info[0][0]=parent->val;
            info[1][0]=level;
        }
        if(root->val == y){
            info[0][1]=parent->val;
            info[1][1]=level;
        }
        solve(root->left,level+1,root,info,x,y);
        solve(root->right,level+1,root,info,x,y);
        return;
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>>info(2,vector<int>(2,-1));
        info[1][0]=0, info[1][1]=0;  //column 0 is for x, column 1 is for y. row 0 will store parents, row 1 stores the levels.
        TreeNode* parent=new TreeNode(-1);
        int level=0;
        solve(root,level,parent,info,x,y);
        if(info[0][0]!=info[0][1] && info[1][0]==info[1][1])
            return true;
        return false;
    }
