class Solution {
public:
    int di[4]={0,0,-1,1};
    int dj[4]={-1,1,0,0};
    void dfs(int i, int j,  vector<vector<char>>&grid){
        grid[i][j]='Y';
        for(int k=0;k<4;k++){
            int newi=i+di[k];
            int newj=j+dj[k];
            if(newi<grid.size() && newi>=0 && newj<grid[0].size() && newj>=0 && grid[newi][newj]=='O')
                dfs(newi, newj,grid);
        }
    }
   
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O')
                dfs(i,0,grid);
            if(grid[i][m-1]=='O')
                dfs(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O')
                dfs(0,i,grid);
            if(grid[n-1][i]=='O')
               dfs(n-1,i,grid);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' ){
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='Y')
                    grid[i][j]='O';
            }
        }
    }
};
