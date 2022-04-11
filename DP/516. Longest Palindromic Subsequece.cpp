int solve(int n, int m, string& s1, string& s2, vector<vector<int>>&t){
        if(n==0 || m==0)
            return t[n][m]=0;
        if(t[n][m]!=-1)
            return t[n][m];
        int ans = 0;
        if(s1[n-1]==s2[m-1])
            return t[n][m]=1+solve(n-1,m-1,s1,s2,t);
        else
            return t[n][m]=max(solve(n-1,m,s1,s2,t), solve(n,m-1,s1,s2,t));
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>t(s.length()+1,vector<int>(s.length()+1,-1));
        return solve(s.length(),s.length(),s1,s,t);
    }
