int solve(int i,int j, string& s1, string& s2,vector<vector<int>>&t){
        if(i==s1.length() && j==s2.length())
            return t[i][j]=0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(j>=s2.size()){                                                        
          int sum=0;
           for(int k=i;k<s1.size();k++)
               sum+=s1[k];
           return t[i][j]=sum;               
       }
        
        if(i>=s1.size()){                                                        
          int sum=0;
           for(int k=j;k<s2.size();k++)
               sum+=s2[k];
           return t[i][j]=sum;               
       }
        if(s1[i]==s2[j])
            return t[i][j] = solve(i+1,j+1,s1,s2,t);
        else{
            int del1 = s2[j]+solve(i,j+1,s1,s2,t);
            int del2 = s1[i]+solve(i+1,j,s1,s2,t);
            return t[i][j]= min(del1,del2);    
        }    
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m=s2.length();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return solve(0, 0, s1, s2, t);
    }
