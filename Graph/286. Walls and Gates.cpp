
    #define ll long long
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int m=rooms[0].size();
        queue<pair<ll,ll>>q;
        vector<vector<ll>>dis(n,vector<ll>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
                    
            }
        }
        while(!q.empty()){
            int c=q.size();
            for(int i=0;i<c;i++){
                auto p=q.front();
                ll x=p.first, y=p.second;
                ll d=dis[x][y];
                q.pop();
                for(int k=0;k<4;k++){
                    ll newx=x+dx[k];
                    ll newy=y+dy[k];
                    if(newx>=0 && newy>=0 && newx<n && newy<m && rooms[newx][newy]==2147483647){
                        dis[newx][newy]=d+1;
                        rooms[newx][newy]=d+1;
                        q.push({newx,newy});
                    }
                }
            }
        }
        
    }
