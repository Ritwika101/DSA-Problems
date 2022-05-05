bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        map<int,bool>vis;
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(u == end)
                return true;
            
            for(auto x : adj[u]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        return false;
    }
