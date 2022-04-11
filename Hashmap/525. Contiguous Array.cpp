int findMaxLength(vector<int>& a) {
        for(int i=0;i<a.size();i++){
            if(a[i]==0)
                a[i]=-1;
        }
        unordered_map<int,int>m;
        m[0]=-1;
        int ans=0,prefix=0;
        for(int i=0;i<a.size();i++){
            prefix+=a[i];
            if(m.find(prefix)==m.end())
                m[prefix]=i;
            else
                ans = max(ans,i-m[prefix]);
        }
        return ans;
    }
