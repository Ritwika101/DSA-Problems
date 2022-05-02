int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        int ans=0,odd=0;
        for(int i=0;i<128;i++){
            if(m[i]&1){
                odd=1;
                ans+=m[i]-1;
            }      
            else
                ans+=m[i];
        }
        return odd+ans;
    }
