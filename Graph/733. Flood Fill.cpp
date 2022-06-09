
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void solve(int x, int y, int n, int m, int old, vector<vector<int>>& image,vector<vector<bool>>&vis, int newColor){
        if(x>n || y>m || x<0 || y<0){
            if(image[x][y]!=newColor)
                return;
        }   
        for(int i=0;i<4;i++){
            int newx=x+dx[i], newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && (image[newx][newy]==old) )
            {
                image[newx][newy]=newColor; 
                vis[newx][newy]=true;
                solve(newx,newy,n,m,old, image,vis,newColor);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int old = image[sr][sc];
        image[sr][sc]=newColor;
        solve(sr,sc,n,m,old,image,vis,newColor);
        return image;
    }
