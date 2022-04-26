class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        int count=0;
        for(int gap=0;gap<s.length();gap++){
            for(int i=0;i<t.size();i++){
                int j=i+gap;
                if(j>=n)
                    break;
                if(gap==0)
                    t[i][j]=true;
                   
                else if(gap==1){
                    if(s[i]==s[j])
                        t[i][j]=true;   
                       
                    else
                        t[i][j]=false;
                }
                else {
                    if(s[i]==s[j] && t[i+1][j-1]==true)
                        t[i][j]=true;
                        
                    else
                        t[i][j]=false;
                    
                }
                if(t[i][j])
                    count+=1;  
            }
            
        }
        
        return count;
        
    }
};
