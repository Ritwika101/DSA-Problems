int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>t(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
            t[n-1][i]=triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                t[i][j]=triangle[i][j]+min(t[i+1][j],t[i+1][j+1]);
            }
        }
        return t[0][0];
    }
