int height(Node* root){
        // code here 
        if(!root)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
        else{
            int r = height(root->right)+1;
            int l = height(root->left)+1;
            return max(l,r);
        }
    }
void printSpiral(Node* root, int level, bool flag, vector<int>&v){
    if(root==NULL)  
        return;
    else if(level == 1)
        v.push_back(root->data);
    else{
        if(flag){
            printSpiral(root->right, level-1,flag,v);
            printSpiral(root->left, level-1,flag,v);
        }
        else if(!flag){
            printSpiral(root->left,level-1,flag,v);
            printSpiral(root->right,level-1,flag,v);
        }
    }
}    
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>v;
    int h=height(root);
    bool flag=1;
    for(int i=1;i<=h;i++){
        printSpiral(root,i,flag,v);
        flag=!flag;
    }
    return v;
}
