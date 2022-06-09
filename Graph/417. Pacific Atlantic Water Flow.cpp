class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(int x, int y, int n, int m, vector<vector<int>>heights, vector<vector<bool>>&ocean){
        
        ocean[x][y]=1;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<0 || newy<0 || newx>=n || newy>=m || ocean[newx][newy]==1 || heights[newx][newy]<heights[x][y])
                continue;
            dfs(newx,newy,n,m,heights,ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
             dfs(0,j,n,m,heights,pacific);
             dfs(n-1,j,n,m,heights,atlantic);
        }
        for(int i=0;i<n;i++){
             dfs(i,0,n,m,heights,pacific);
             dfs(i,m-1,n,m,heights,atlantic);
        }  
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
