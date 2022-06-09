int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int solve(int x, int y, int n, int m, vector<vector<bool>>&vis, vector<vector<int>>&grid){
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || grid[x][y]==0)
            return 0;
        int ans = 0;
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            ans += solve(newx,newy,n,m,vis,grid);
        }
        ans+=1;
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    area = max(area,solve(i,j,n,m,vis,grid));
                }
            }
        }
        return area;
    }
