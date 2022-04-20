bool isPalindrome(string s) {
        string r=""; 
        for(int i=0;i<s.length();i++){    
            int x = s[i]-'0';
            if( (tolower(s[i])>=97 &&  tolower(s[i])<=122) || (x>=0 && x<=9) )
                r+=tolower(s[i]);
        }
        int n=r.length();
        int i=0, j=n-1;
        if(n==0 || n==1)
            return true;
        while(i<j){
            if(r[i]!=r[j])
                return false;
            i+=1;
            j-=1;
        }
        return true;
        
    }
