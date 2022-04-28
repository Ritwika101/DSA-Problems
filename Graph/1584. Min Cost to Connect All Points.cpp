class Solution {
public:
    typedef pair<int, int> pi;
    int minCostConnectPoints(vector<vector<int>>& points) { 
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j,dis});
                    adj[j].push_back({i,dis});
                }
            }
        }
        vector<int>dis(n,INT_MAX);
        vector<int>parent(n,-1);
        int sum=0;
        vector<int>vis(n,0);
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        pq.push({0,0});
        dis[0]=0;
        parent[0]=-1;
        int count=0;
        while(count<n){
            auto p = pq.top();
            pq.pop();
            int w=p.first;
            int u=p.second;
            if(vis[u])
                continue;
            sum+=w;
            vis[u]=1;
            count+=1;
            for(auto x:adj[u]){
                if(!vis[x.first]){
                    int v=x.first;
                    int d=x.second;
                    if(dis[v]>d && !vis[v]){
                        parent[v]=u;
                        dis[v]=d;
                        pq.push({d,v});
                    }
                }
                
            }
          
        }
        return sum;
    }
};
