int countNode(struct Node* root){
    if(!root)
        return 0;
    return 1+(countNode(root->left)+countNode(root->right));
}
bool CBT(struct Node* root, int i, int n){
    if(!root) return true;
    if(i>=n) return false;
    return (CBT(root->left,2*i+1,n) && CBT(root->right,2*i+2, n));
}
bool solve(struct Node* root){
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;
    bool l = solve(root->left);
    bool r = solve(root->right);
    if(!l || !r) return false;
    bool left = true;
    bool right = true;
    if(root->left) left = root->key>=root->left->key;
    if(root->right) right = root->key>=root->right->key;
    return left&&right;
}

bool isHeap(struct Node* root) {
    // your code here
    if(!root)
        return true;
    int n = countNode(root);
    return solve(root) && CBT(root,0,n);
    return solve(root);
