class Solution {
public:
    void solve(TreeNode* root,vector<int>&res){
        if(!root)
            return;
        if(!root->left && !root->right)
            res.push_back(root->val);
        solve(root->left,res);
        solve(root->right,res);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        vector<int>res1;
        vector<int>res2;
        solve(root1, res1);
        solve(root2, res2);
        return res1 == res2;
    }
};
