class Solution {
public:

    bool dfs(unordered_map<int,vector<int>>& adj, int u, map<int,int>& vis, stack<int>& res)
    {
        vis[u]=1;
        for(auto v:adj[u])
        {
            if(vis[v]==1 || (vis[v]==0 && dfs(adj,v,vis,res)))
                return true;
        }
        vis[u]=2;
        res.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges)
    {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++)
            adj[edges[i][1]].push_back(edges[i][0]);
        map<int,int>vis;
        stack<int>res;
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,i,vis,res))
                    return {};
            }
        } 
        vector<int>s;
        while(!res.empty())
        {
            s.push_back(res.top());
            res.pop();
        }
        return s;
    }
};
