string removeDuplicates(string s, int k) {
        int n=s.size();
        vector<pair<char,int>>v;
        for(int i=0;i<n;i++){
            int last = v.size()-1;
            if(v.size()==0 || v[last].first!=s[i])
                v.push_back({s[i],1});
            else if(v[last].first==s[i]){
                if(v[last].second<k-1)
                   v[last].second+=1; 
                else 
                     v.pop_back();
            } 
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++)
                ans.push_back(v[i].first);
        }
        return ans;
    }
