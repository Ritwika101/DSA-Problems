int dfs(int x, int y, vector<vector<int>>&dis,int matrix[M][N], int &maxh, int m, int n){
        if(x<0 || x>=m || y<0 || y>=n)
	          return 0;
        if(dis[x][y]!=-1)
            return dis[x][y];
        dis[x][y]=1;
        int ans=0;
        ans=max(ans,dfs(x+1,y,dis,matrix,maxh,m,n));
	      ans=max(ans,dfs(x,y+1,dis,matrix,maxh,m,n));
	      ans=ans+1;
        return dis[x][y]=ans;
    }
    int findSnakeSequence(int matrix[M][N]) {
        int m = M;
        int n = N;
        vector<vector<int>>dis(m, vector<int>(n, -1));
        int maxh=1;
        int result = 1;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                result = max(dfs(x,y,dis,matrix,maxh, m,n), result);
            }   
        }
        return result;
    }
