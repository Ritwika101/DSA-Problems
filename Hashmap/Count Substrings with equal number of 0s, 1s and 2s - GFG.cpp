long long getSubstringWithEqual012(string str) {
        // code here
        vector<int>a;
        map<pair<ll,ll>,ll>m;
        ll z0=0,z1=0,z2=0,ans=0;
        m[{0,0}]=1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')
                z0++;
            else if(str[i]=='1')
                z1++;
            else
                z2++;
            ll d0 = z1-z0;
            ll d1 = z2-z1;
            pair<ll,ll>p = {d0,d1};
            if(m[p]==0)
                m[p]++;
            else{
                ans+=m[p];
                m[p]++;
            }
        }
        return ans;       
    }
