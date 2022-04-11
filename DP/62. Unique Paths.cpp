int uniquePaths(int m, int n) {
        int count = 0;
        vector<vector<int>>t(n,vector<int>(m,0));
        t[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1 )
                    t[i][j]+=t[i+1][j];
                if(j<m-1)
                    t[i][j]+=t[i][j+1];
            }
        }
        return t[0][0];
    }


