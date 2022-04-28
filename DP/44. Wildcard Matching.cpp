
class Solution {
public:
    bool solve(int i, int j, int n, int m, string& s, string& p, vector<vector<int>>&dp){
        if(i<0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
       
        if(i<0 && j>=0 ){
            for(int k=j;k>=0;k--){
                if(p[k]!='*')
                    return false;
            }
             return true;
        }
         if(dp[i][j]!=-1)
            return dp[i][j];
           
        bool ans=false;
        if(s[i]==p[j] || p[j]=='?'){
             ans=ans || solve(i-1,j-1,n,m,s,p,dp);
             if(ans)
                return dp[i][j] = true;
        }
        else if(p[j]=='*'){
           
            ans = ans || solve(i,j-1,n,m,s,p,dp);
            if(ans) return dp[i][j] = true;
            ans = ans || solve(i-1,j,n,m,s,p,dp);
            if(ans) return dp[i][j] = true;
        }
         return dp[i][j] = false;        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s.length()-1,p.length()-1,s.length(),p.length(),s,p,dp);
    }
};
