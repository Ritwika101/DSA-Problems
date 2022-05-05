
vector<int> topView(Node *root)
    {
        //Your code here
            vector<int>v;
        map<int,vector<int>>m;
        queue<pair<Node*, int>>q;
        if(!root)
            return v;
        q.push({root,0});
        //int hd = 0;
        while(!q.empty()){
            int hd = q.front().second;
            Node* curr= q.front().first;
            q.pop();
            m[hd].push_back(curr->data);
            if(curr->left)
                q.push({curr->left,hd-1});
            if(curr->right)
                q.push({curr->right,hd+1});
        }
        for(auto it : m){        
                v.push_back(it.second[0]);
        }
        return v;
    }
