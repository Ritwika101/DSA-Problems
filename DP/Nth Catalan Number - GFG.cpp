cpp_int solve(int n, vector<cpp_int>&t){
        if(n<=1)
        {
            t[n]=1;
            return t[n];
        }
        cpp_int ans = 0;
        if(t[n]!=-1)
            return t[n];
        for(int i=0;i<=n-1;i++){
            ans+=(solve(i,t)*solve(n-1-i,t));
        }
        t[n] = ans;
        return ans;
    }
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int>t(n+1,-1);
        return solve(n,t);
    }
