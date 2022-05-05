bool dfs(int u, vector<int> adj[], int parent, vector<bool>&vis){
        vis[u]=true;
        for(auto v : adj[u]){
            if(vis[v]){
                if(parent!=v)
                    return true;
            }
            else{
                if(dfs(v,adj,u,vis))
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>vis(v);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,-1,vis))
                    return true;
            }
        }
        return false;
    }
