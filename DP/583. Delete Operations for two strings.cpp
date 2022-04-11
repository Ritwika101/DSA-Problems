int solve(int n, int m, string& s1, string& s2, vector<vector<int>>&t){
        if(n==0 || m==0)
            return t[n][m]=0;
        if(t[n][m]!=-1)
            return t[n][m];
        if(s1[n-1]==s2[m-1])
            return t[n][m]=1+solve(n-1,m-1,s1,s2,t);
        else{
            int ans= 0;
            ans = max(solve(n-1,m,s1,s2,t),solve(n,m-1,s1,s2,t));
            return t[n][m]=ans;
        }
            
    }
    int minDistance(string s1, string s2) {
       vector<vector<int>>t(s1.length()+1,vector<int>(s2.length()+1,-1));
        int len =  solve(s1.length(),s2.length(),s1,s2,t);
        int del = s1.length()-len;
        int ins = s2.length()-len;
        return del+ins;
    }
