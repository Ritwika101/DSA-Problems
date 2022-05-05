
void leftUtil(Node* root, vector<int>&v, int level, int& maxLevel){
    if(!root)
        return;
    if(maxLevel < level){
        v.push_back(root->data);
        maxLevel = level;
    }
    leftUtil(root->left,v,level+1,maxLevel);
    leftUtil(root->right,v,level+1,maxLevel);
    
    
}
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int>v;
    int maxLevel = 0;
    leftUtil(root,v,1,maxLevel);
    return v;
}
