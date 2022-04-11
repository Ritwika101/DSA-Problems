int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>t(n,vector<int>(m,0));
        t[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1 && j<m-1)
                    t[i][j]=grid[i][j]+min(t[i+1][j], t[i][j+1]);
                else if(i<n-1)
                    t[i][j]=grid[i][j]+t[i+1][j];
                else if(j<m-1)
                    t[i][j]=grid[i][j]+t[i][j+1];
            }
        }
        return t[0][0];
    }
