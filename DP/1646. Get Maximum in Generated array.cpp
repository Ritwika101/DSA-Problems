int getMaximumGenerated(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        vector<int>v(n+1);
        int maxnum = 1;
        v[0]=0;
        v[1]=1;
        for(int i=1;i<=n;i++){
            int k = 2*i;
            if(k>=2 && k<=n){
                v[k] = v[i];
                maxnum = max(maxnum,v[k]);
            } 
            int j = 2*i +1;
            if(j>=2 && j<=n){
                v[j] = v[i]+v[i+1];
                maxnum = max(maxnum,v[j]);
            } 
        }
        
        return maxnum;
    }
