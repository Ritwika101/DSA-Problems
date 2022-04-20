class Solution {
public:
    void solve(TreeNode* root, int x, int& sum ){
        if(!root)
            return;
        x = x<<1;
        x+=root->val;
        if(!root->left && !root->right){
           sum+=x;
        }
        solve(root->left,x,sum);
        solve(root->right,x,sum);
        return;
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int x=0;
        int sum=0;
        solve(root,x,sum);
        return sum;
    }
};
