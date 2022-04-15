bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
       unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
            m[s[i]]+=1;
        for(int i=0;i<t.length();i++){
            if(m[t[i]]==0)
                return false;
            m[t[i]]-=1;
        }
        return true;
    }
