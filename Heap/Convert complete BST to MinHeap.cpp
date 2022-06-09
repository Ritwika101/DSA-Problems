void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void store(Node* root, vector<int>arr, int i){ 
    if(root==NULL) return;  
    root->val=arr[i];
    i++;  
    store(root->left,arr,i);
    store(root->right,arr,i);
}
Node* solve(Node* root){
   if(root==NULL) return NULL;
   vector<int>arr;
   inorder(root,arr);
   store(root,arr,0);
   return root;
   
}
