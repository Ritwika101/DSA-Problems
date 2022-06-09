
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
class Solution {
public:
    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y]==1 || grid[x][y]=='0')
            return;
        vis[x][y]=true;
        for(int i=0;i<4;i++){
           int newx=x+dx[i],newy=y+dy[i];
           if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && !vis[newx][newy] && grid[newx][newy]=='1'){
               dfs(newx,newy,vis,grid);
           }
        }
        return;    
       
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited( m , vector<bool> (n, false));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&visited[i][j]==false){
                    ans++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return ans;
    }
};
