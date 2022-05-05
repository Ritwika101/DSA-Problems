class Solution {
public:
    void dfs(vector<vector<int>>&graph, int n,vector<bool>&vis,vector<vector<int>>&result,vector<int>&path,int u )
    {
        path.push_back(u);
        if(u==n-1)
        {
            result.push_back(path);
            path.pop_back();
            return;
        } 
        vis[u]=true;
        for(auto v:graph[u]) 
        {
            if(!vis[v])
                dfs(graph,n,vis,result,path,v);
        }
        vis[u]=false;
        path.pop_back();
        
    }  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,0);
        vector<vector<int>> result;
        vector<int>path;
        
        dfs(graph,n,visited,result,path,0);//dfs 
        return result;
        
        
    }
};
