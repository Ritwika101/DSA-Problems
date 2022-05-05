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
void printCurrentLevel(Node* root, int level, vector<int>&v){
        if(root==NULL)
            return;
        else if(level == 1)
            v.push_back(root->data);
        else{
            printCurrentLevel(root->left,level-1,v);
            printCurrentLevel(root->right,level-1,v);
        }
    }
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      int h=height(root);
      vector<int>v;
      for(int i=1;i<=h;i++)
        printCurrentLevel(root,i,v);
      return v;
    }
