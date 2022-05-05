class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=true;
            for(auto v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        if(find(vis.begin(),vis.end(),false)==vis.end())
            return true;
        else
            return false;
    }
