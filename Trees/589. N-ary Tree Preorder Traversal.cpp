class Solution {
public:
    void preorder(Node* root, vector<int>&res){
        if(!root)
            return;
        res.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            preorder(root->children[i],res);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }
};
