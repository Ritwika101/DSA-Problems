int characterReplacement(string s, int k) {
        int rel=0;
        int n=s.size();
        int ans=0;
        unordered_map<int,int>m;
        for(int acq=0;acq<n;acq++){
            m[s[acq]-'A']++;
            int maxfreq=INT_MIN;
            for(int i=0;i<26;i++){
                maxfreq=max(maxfreq,m[i]);
            }
            int len = acq-rel+1;
            int replacements = len - maxfreq;
            if(replacements<=k)
                ans = max(ans,len);
            while(rel<acq && replacements>k){
                m[s[rel]-'A']--;
                rel++;
                int temp_maxfreq=INT_MIN;
                for(int i=0;i<26;i++){
                    temp_maxfreq=max(temp_maxfreq,m[i]);
                }
                len = acq-rel+1;
                replacements = len - temp_maxfreq; 
            }
            if(replacements<=k)
                ans = max(ans,len);
        }
        return ans;
    }
