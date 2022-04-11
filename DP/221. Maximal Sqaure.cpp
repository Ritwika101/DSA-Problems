int t[301][301];
    int solve(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i==n || j==m || grid[i][j]=='0')
            return t[i][j]=0;
        if(t[i][j]!=-1)
            return t[i][j];
        int ways = 1+min(solve(i+1,j,n,m,grid),min(solve(i,j+1,n,m,grid), solve(i+1,j+1,n,m,grid)));
        return t[i][j]=ways;
    }
    int maximalSquare(vector<vector<char>>& grid) {
        memset(t,-1,sizeof(t));
        int n=grid.size();
        int m=grid[0].size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                    int x = solve(i,j,n,m,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,t[i][j]);
            }
        }
        if(ans==-1)
            return 0;
        else
            return ans*ans;
        
    }
 
