
class Solution {
public:
    const int dx[4]={0,0,1,-1};
    const int dy[4]={1,-1,0,0};
    int dfs(int x, int y, vector<vector<int>>&dis, vector<vector<int>>&matrix, int m, int n){
        if(dis[x][y]!=-1)
            return dis[x][y];
        
        int ans=0;
        for(int i=0;i<4;i++){
            int newx=x+dx[i], newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<m && newy<n && matrix[newx][newy]>matrix[x][y] ){
                ans=max(ans,dfs(newx,newy,dis,matrix,m,n));
            }
        }
        ans+=1;
        return dis[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 1;
        vector<vector<int>>dis(m, vector<int>(n, -1));
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                result=max(result,dfs(x,y,dis,matrix,m,n));
            }   
        }
        return result;
    }
};
