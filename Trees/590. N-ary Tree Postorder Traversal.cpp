class Solution {
public:
    void postorder(Node* root, vector<int>&res){
        if(!root)
            return;
        for(int i=0;i<root->children.size();i++)
            postorder(root->children[i],res);
        res.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int>res;
        postorder(root,res);
        return res;
    }
};
