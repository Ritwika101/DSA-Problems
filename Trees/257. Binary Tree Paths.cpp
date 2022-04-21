

void solve(TreeNode* root,string& ans,vector<string>&res){
        if(!root)
            return;
        if(!root->left && !root->right){
            string old = ans;
            string temp = to_string(root->val);
            ans+=temp;
            res.push_back(ans);
            ans = old;
            return;
        }
        string old=ans;
        string x = to_string(root->val);
        x+="->";
        ans+=x;
        solve(root->left,ans,res);
        solve(root->right,ans,res);
        ans=old;
        return;
            
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string ans="";
        solve(root,ans,res);
        return res;
    }
