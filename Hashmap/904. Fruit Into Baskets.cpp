class Solution {
public:
    #define ll long long
    int totalFruit(vector<int>& s) {
        unordered_map<ll,ll>m;
        int rel = 0;
        ll distinct=0;
        int ans=INT_MIN;
        int n=s.size();
        
        for(int acq=0;acq<n;acq++){
            if(m[s[acq]]==0)
                distinct+=1;
            m[s[acq]]+=1;
            
            while(rel<acq && distinct>2){
                m[s[rel]]-=1;
                if(m[s[rel]]==0)
                    distinct-=1;
                rel+=1;
            }
            ans=max(ans,acq-rel+1);

        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};
