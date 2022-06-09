class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time = 0;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>dis(n,vector<int>(m,0));
        int total=0,rot=0,fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total++;
                    fresh++;
                }
                    
                else if(grid[i][j]==2){
                    rot++;
                    q.push({i,j});
                    total++;
                    dis[i][j]=0;
                    vis[i][j]=true;
                }
            }
        }
        
        while(!q.empty()){
            int c = q.size();
            for(int k=0;k<c;k++){
                auto p = q.front();
                int x=p.first, y=p.second;
                int d = dis[x][y];
                q.pop();
                total--;
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1){
                        fresh--;
                        grid[newx][newy]=2;
                        dis[newx][newy]=d+1;
                        time=max(dis[newx][newy],time);
                        q.push({newx,newy});
                    }
                }
            }
            
        }
        if(fresh==0) return time;      
        return -1;
            
    }
};
