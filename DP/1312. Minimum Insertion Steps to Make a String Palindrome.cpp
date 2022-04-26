

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>t(n+1,vector<int>(n+1,0));
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=max(1+t[i-1][j-1],t[i][j]);
                }
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                
            }
        }
        int res = n - t[n][n];
        return res;
        
    }
};
