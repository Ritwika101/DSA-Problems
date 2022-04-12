int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,ll>m;
        int rel = 0;
        ll distinct=0;
        int ans=INT_MIN;
        int n=s.length();
        if(k==0)
            return 0;
        for(int acq=0;acq<n;acq++){
            if(m[s[acq]]==0)
                distinct+=1;
            m[s[acq]]+=1;
            
            while(rel<acq && distinct>k){
                m[s[rel]]-=1;
                if(m[s[rel]]==0)
                    distinct-=1;
                rel+=1;
            }
            if(distinct == k)
                ans=max(ans,acq-rel+1);

        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
