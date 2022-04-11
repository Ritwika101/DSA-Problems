
int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>>t(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
            t[n-1][j]=grid[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int start=0;
                if(j==0)
                {
                    int temp=INT_MAX;
                    for(int k=j+1;k<m;k++)
                        temp=min(temp,t[i+1][k]);
                    t[i][j]=grid[i][j]+temp;
                }
                else if(j==n-1){
                    int temp=INT_MAX;
                    for(int k=j-1;k>=0;k--)
                        temp=min(temp,t[i+1][k]);
                    t[i][j]=grid[i][j]+temp;
                }
                else{
                    int temp=INT_MAX;
                    for(int k=0;k<m;k++){
                        if(k!=j)
                            temp=min(temp,t[i+1][k]);
                    }
                    t[i][j]=grid[i][j]+temp;
                }
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
            ans=min(ans,t[0][j]);
        return ans;
    }
