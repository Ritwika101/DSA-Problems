
int minFallingPathSum(vector<vector<int>>& grid) {
        //memset(t,-1,sizeof(t));
        int m=grid.size();
        int n=grid[0].size();
        int cost = INT_MAX;
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            mat[m-1][j]=grid[m-1][j];
        }
            
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int cost =0;
                if(j==0&& j<n-1)
                    cost = grid[i][j]+min(mat[i+1][j+1],mat[i+1][j]);
                else if(j==n-1 && j>0)
                    cost =grid[i][j]+ min(mat[i+1][j], mat[i+1][j-1]) ;         
                else
                    cost = grid[i][j]+min(mat[i+1][j+1], min(mat[i+1][j], mat[i+1][j-1]));
                mat[i][j]=cost;
            }    
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,mat[0][i]);
        }   
        return ans;
    }
