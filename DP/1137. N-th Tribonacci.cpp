int solve(int n, vector<int>&t){
        if(n==0)
            return t[n]=0;
        if(n==1 || n==2)
            return t[n]=1;
        if(t[n]!=-1)
            return t[n];
        else
            return t[n]=solve(n-1,t)+solve(n-2,t)+solve(n-3,t);
        
    }
    int tribonacci(int n) {
        vector<int>t(n+1,-1);
        if(n==0)
            return t[n]=0;
        if(n==1 || n==2)
            return t[n]=1;
        t[0]=0;
        t[1]=1;
        t[2]=1;
        return solve(n,t);
        
    }
