int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
        int ans=0;
        int rel=0;
        int n = s.length();
        unordered_map<char,int>m;
        for(int acq=0;acq<n;acq++){
            while(rel<acq && m[s[acq]]>0){
                m[s[rel]]-=1;
                rel+=1;
            }
            m[s[acq]]+=1;
            int new_len = acq-rel+1;
            ans = max(ans,new_len);
        }
        return ans;
    }
