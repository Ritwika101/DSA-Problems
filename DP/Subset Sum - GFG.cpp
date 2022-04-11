bool isSubsetSum(int n, int a[], int s){
        // code here 
        int t[n+1][s+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(a[i-1]<=j)
                    t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][s];
    }
