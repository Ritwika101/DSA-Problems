int solve(int n, vector<int>&v, vector<int>c, int maxlevel){
        if(n<=0)
            return v[key] = 0;
        int key=n;
        if(v[key]!=INT_MAX && n!=maxlevel)
            return v[key];
        int one = solve(n-1,v,c,maxlevel);
        int two = solve(n-2,v,c,maxlevel);
        return v[n]= min(one,two)+c[n];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>v(n+2,INT_MAX);
        v[0]=0;
        v[n+1]=0;
        vector<int>c(n+2,0);
        for(int i=0;i<n;i++){
            c[i+1]=cost[i];
        }
        return solve(n+1,v,c,n+1);
    }
