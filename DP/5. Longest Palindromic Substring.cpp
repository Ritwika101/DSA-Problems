


class Solution {
public:
    string longestPalindrome(string s) {
       string result="";
        int n=s.length();
        vector<vector<bool>>t(n,vector<bool>(n));
        int ans=0,start=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n;i++){
                int j=i+gap;
                if(j>=n)
                    break;
                if(gap==0){
                    t[i][j]=true;
                    if(ans<gap+1){
                        ans=gap+1;
                        start=i;
                    }   
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                        t[i][j]=true;
                        if(ans<gap+1){
                            ans=gap+1;
                            start=i;
                        }      
                    }
                }
                else{
                    if(s[i]==s[j] && i<n-1 && j>0 && t[i+1][j-1]==true){
                        t[i][j]=true;
                        if(ans<gap+1){
                            ans=gap+1;
                            start=i;
                        }      
                    }
                }
            }
        }
        result+=s.substr(start,ans);
        return result;
        
    }
};
