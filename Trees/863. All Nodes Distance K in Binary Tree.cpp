

class Solution {
public:
     bool vis[502]={false};
    void find(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parents, TreeNode* p){
        if(!root)
            return;
        parents[root]=p;
        find(root->left,parents,root);
        find(root->right,parents,root);
    }
    void solve(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parents, int k, vector<int>&ans){
        if(!root)
            return;
        if(vis[root->val])
            return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        vis[root->val]=true;
        solve(root->left,parents,k-1,ans);
        solve(root->right,parents,k-1,ans);
        solve(parents[root],parents,k-1,ans);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parents;
        find(root,parents,NULL);
        vector<int>ans;
        solve(target,parents,k,ans);
        return ans;
    }
};
