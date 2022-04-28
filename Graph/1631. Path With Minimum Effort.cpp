class Solution {
public:
    int di[4]={0,0,1,-1};
    int dj[4]={1,-1,0,0};
    int sum=0;
    int dijkstra(vector<vector<int>>& heights,vector<vector<bool>>&vis, int n,int m){
        int sum=0;
        set<pair<int,pair<int,int>>>s;
        
        s.insert({0, {0,0}});
        vis[0][0]=true;
        
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));   
        dis[0][0]=0;
        while(!s.empty()){
            auto x =*(s.begin());
            s.erase(s.begin());
            pair<int,int>u=x.second;
            int w = x.first;
            sum=w;
            if(u.first==n-1 && u.second==m-1)
                return w;
            vis[u.first][u.second]=true;
            for(int i=0;i<4;i++){
                int vi=u.first+di[i];
                int vj=u.second+dj[i];
                if(vi>=0 && vj>=0 && vi<n && vj<m && !vis[vi][vj] ){
                    int d = abs(heights[u.first][u.second]-heights[vi][vj]);
                    int newd = max(d,w);
                    if(newd<dis[vi][vj]){
                        auto f=s.find({dis[vi][vj],{vi,vj}});
                        if(f!=s.end())
                            s.erase(f);
                        dis[vi][vj]=newd;
                        s.insert({dis[vi][vj],{vi,vj}});
                    
                    }
                
                }
            }
        }
        return sum;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n<=1 && m<=1)
            return 0;
       
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        return dijkstra(heights,vis,n,m);
        
    }
};
