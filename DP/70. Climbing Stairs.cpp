
int climbStairs(int n) {
        vector<int>v(n+1,0);
        v[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<=n)
                v[i]+=v[i+1];
            if(i+2<=n)
                v[i]+=v[i+2];
        }
        return v[0];
       
    }
