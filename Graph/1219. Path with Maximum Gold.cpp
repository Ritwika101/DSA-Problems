class Solution {
public:
    const int dx[4]={0,0,1,-1};
    const int dy[4]={1,-1,0,0};
    int ans=0;
    void dfs(int x ,int y, vector<vector<bool>> &vis, vector<vector<int>> &grid, int& val)
    {
        vis[x][y]=true;
        val=val+grid[x][y];
        ans=max(ans,val);
        for(int i=0;i<4;i++){
            int newx=x+dx[i], newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && !vis[newx][newy] && grid[newx][newy]!=0)
            {
                dfs(newx,newy,vis,grid,val);
            }
        }
        
        vis[x][y]=false;
        val-=grid[x][y];
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int val=0;
     
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
             if(grid[i][j]!=0)
                dfs(i,j,visited,grid,val);   
            }
        }
        return ans;
        
    }
   
};
