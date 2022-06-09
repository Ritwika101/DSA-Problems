bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<s1.size();i++){
            m1[s1[i]-'a']++;
        }
        int rel=0;
        int ans=0;
        int n = s1.size();
        if(n>s2.size()) return false;
        for(int i=0;i<n;i++){
            m2[s2[i]-'a']++;
        }
        bool flag=true;
        int matches=0;
        int total=0;
        for(int i=0;i<26;i++){
            total+=m1[i];
        }
        for(int i=0;i<26;i++){
            if(m2[i]<=m1[i] && m1[i]>0){
                matches+=m2[i];
            } 
            else if(m2[i]>m1[i])
                matches+=m1[i];
        }
        if(matches==total) return true;
        for(int acq=n;acq<s2.size();acq++){
            m2[s2[acq]-'a']++;
            if(m2[s2[acq]-'a']<=m1[s2[acq]-'a'] && m2[s2[acq]-'a']>0)
                matches++;
            if(m2[s2[rel]-'a']<=m1[s2[rel]-'a'] && m2[s2[rel]-'a']>0)
                matches--;
            m2[s2[rel]-'a']--;
            rel++;
            if(total==matches)
                return true;
            
        }
        return false;
    }
