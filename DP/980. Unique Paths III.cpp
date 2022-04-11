class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
   void dfs(int x, int y, int dest_x, int dest_y, int n, int m, vector<vector<bool>>&vis, vector<vector<int>>grid, int &ways, int count, int total ){
       if(x>=grid.size() || y>=grid[0].size() || x<0 || y<0 || grid[x][y]==-1)
            return;
       vis[x][y]=true;
       if(x==dest_x && y==dest_y && count==total+1)
       {   
           ways++;
           vis[x][y]=false;
           return;
       }
       else if(x==dest_x && y==dest_y && count!=total+1){
           vis[x][y]=false;
           return;
       }
       for(int i=0;i<4;i++){
           int newx=x+dx[i];
           int newy=y+dy[i];
    
           if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && grid[newx][newy]!=-1){
               
               dfs(newx, newy, dest_x, dest_y, n, m, vis, grid, ways, count+1, total);
           }
             
       }
       vis[x][y]=false;
   }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_i, start_j, end_i, end_j;
        int n = grid.size();
        int m=grid[0].size();
        int total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    start_i=i;
                    start_j=j;
                }
                else if(grid[i][j]==2){
                    end_i=i;
                    end_j=j;
                }
                else if(grid[i][j]==0){
                    total++;
                }
                    
            }
        }
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ways = 0;
        int count = 0;
        dfs(start_i, start_j, end_i, end_j, n, m, vis, grid, ways, count, total);
        return ways;
    }
