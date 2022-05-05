int solve(int u, int n, vector<int>&path, vector<bool>&vis, vector<int> adj[], int dest ){
        if(u==dest){
            return 1; //you got a path
        }
        path.push_back(u);
        vis[u]=true;
        int ans=0;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!vis[v]){
                ans+=solve(v,n,path,vis,adj,dest); //add up all possible ways
            }
        }
        vis[u]=false;
        path.pop_back();
        return ans; //will return 0, if there are no ways
    }
    int countPaths(int v, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool>vis(v);
        vector<int>path;
        return solve(source,v,path, vis, adj, destination);
    }
