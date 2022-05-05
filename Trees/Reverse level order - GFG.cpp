
vector<int> reverseLevelOrder(Node *root)
{
    // code here
      vector<int>v;
      queue<Node*>q;
      stack<Node*>s;
      q.push(root);
      Node* curr;
      while(!q.empty()){
          curr=q.front();
          q.pop();
          s.push(curr);
          if(curr->right)
            q.push(curr->right);
          if(curr->left)
            q.push(curr->left);
          
      }
      while(!s.empty()){
          v.push_back(s.top()->data);
          s.pop();
      }
      return v;
}
