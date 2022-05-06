 bool bipartiteBFS(vector<vector<int>>graph,vector<int>color,int u){
         queue<int>q;
         color[u]=1;
         q.push(u);
         while(!q.empty()){
             int u = q.front();
             q.pop();
             for(auto v:graph[u]){
                 if(color[v]==-1){
                     color[v]=1-color[u];
                     q.push(v);
                 }
                 else if(color[v]==color[u])
                     return false;
             }
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(auto i=0;i<n;i++){
            if(color[i]==-1){
                if(!bipartiteBFS(graph,color,i)){
                    return false;
                }
            }
        }
        
      return true;  
    }
