int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count = 0;
        vector<vector<ll>>t(n,vector<ll>(m,0));
        if(grid[n-1][m-1]==1)
            return 0;
        t[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==1)
                    t[i][j]=0;
                else{
                    if(i<n-1)
                        t[i][j]+=t[i+1][j];
                    if(j<m-1)
                        t[i][j]+=t[i][j+1];
                }
            }
        }
        return t[0][0];
    }
