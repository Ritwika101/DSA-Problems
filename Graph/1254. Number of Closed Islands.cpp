class Solution {
public:
    int di[4]={0,0,-1,1};
    int dj[4]={-1,1,0,0};
    void dfs(int i, int j,  vector<vector<int>>&grid){
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int newi=i+di[k];
            int newj=j+dj[k];
            if(newi<grid.size() && newi>=0 && newj<grid[newi].size() && newj>=0 && grid[newi][newj]==0)
                dfs(newi,newj,grid);
        }
    }
   
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       // vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
                dfs(i,0,grid);
            if(grid[i][m-1]==0)
                dfs(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)
                dfs(0,i,grid);
            if(grid[n-1][i]==0)
               dfs(n-1,i,grid);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
