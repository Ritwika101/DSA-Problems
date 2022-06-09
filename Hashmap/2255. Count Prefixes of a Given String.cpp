int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(int i=0;i<words.size();i++){
            string pre = words[i];
            int j=0,breakpt=0;
            string prefix = s.substr(0,pre.size());
            if(pre==prefix)
                count++;
        }
        return count;
    }

