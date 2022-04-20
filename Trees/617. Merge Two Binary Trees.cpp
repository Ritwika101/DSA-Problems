class Solution {
public:
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return NULL;
        else if(root1 && !root2){
            TreeNode* temp = new TreeNode(root1->val);
            temp->left = solve(root1->left, NULL);
            temp->right = solve(root1->right, NULL);
            return temp;
        }
        else if(root2 && !root1){
            TreeNode* temp = new TreeNode(root2->val);
            temp->left = solve(NULL, root2->left);
            temp->right = solve(NULL, root2->right);
            return temp;
        }
        else{
            TreeNode* temp = new TreeNode(root1->val+root2->val);
            temp->left = solve(root1->left, root2->left);
            temp->right = solve(root1->right, root2->right);
            return temp;
        }
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
