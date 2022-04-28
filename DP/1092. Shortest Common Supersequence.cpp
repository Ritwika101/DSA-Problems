
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s1=str1, s2=str2;
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    t[i][j]=t[i-1][j-1]+1;
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i-=1;
                j-=1;
            }
            else if(t[i-1][j] > t[i][j-1]){
                ans.push_back(s1[i-1]);
                i-=1;
            }
            else{
               ans.push_back(s2[j-1]);
               j-=1; 
            }
        }
        while(i>0)
        {
            ans.push_back(s1[i-1]);
            i-=1;
        }
        while(j>0)
        {
            ans.push_back(s2[j-1]);
            j-=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
