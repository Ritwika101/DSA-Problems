class Solution {
public:
    bool dfs( vector<vector<int>>&adj,vector<int>&color, int u ){
        for(auto v : adj[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                if(!dfs(adj,color,v))
                    return false;
            }
            else if(color[v]==color[u])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!dfs(adj,color,i))
                    return false;
            }
               
        }
        return true;
    }
};
