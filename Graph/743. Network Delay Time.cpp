class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool>vis(n+1,false);
        unordered_map<int, vector<pair<int, int>>>adj;
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
       
        vis[k]=true;
        dis[k]=0;
        vis[0]=true;
        dis[0]=0;
        int maxtime = 0;
        set<pair<int,int>>s;
        s.insert({0,k});
        while(!s.empty()){
            auto p = *(s.begin());
            int u = p.second;
            s.erase(s.begin());
            vis[u]=true;
            for(auto x : adj[u]){
                int v = x.first;
                int w = x.second;
                if(!vis[v] && dis[v] >w+dis[u] ){
                    auto f = s.find({dis[v],v});
                    if(f!=s.end())
                        s.erase(f);
                    dis[v]=w+dis[u];
                    s.insert({dis[v],v});
                }
            }
        }
       
        if(find(vis.begin(), vis.end(),false)==vis.end()){
             for(int i=0;i<=n;i++){
                 maxtime = max(maxtime, dis[i]);
             }
            return maxtime;
        }
           
        else
            return -1;
    }
}; 
