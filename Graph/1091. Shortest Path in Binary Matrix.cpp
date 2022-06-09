
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int bfs(int x, int y, int n, int m, vector<vector<int>>grid, vector<vector<bool>>&vis){
        if(x>=n || y>=m || x<0 || y<0 || vis[x][y] ||grid[x][y]==1)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        vector<vector<int>>dis(n,vector<int>(m,0));
        dis[0][0]=1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int d = dis[x][y];
            q.pop();
            if(x==n-1 && y==m-1) return dis[x][y];
            for(int i=0;i<8;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx<n && newy<m & newx>=0 && newy>=0 && !vis[newx][newy] && grid[newx][newy]==0){
                    dis[newx][newy]=dis[x][y]+1;
                    vis[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        if(grid[0][0]==1)
            return -1;
        return bfs(0,0,n,m,grid,vis);
    }
};
