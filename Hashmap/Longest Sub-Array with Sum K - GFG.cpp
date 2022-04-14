int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int prefix=0,ans=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<n;i++){
            prefix+=a[i];
            if(m.find(prefix-k)!=m.end())
                ans=max(ans,i-m[prefix-k]);
            if(m.find(prefix)==m.end())
                m[prefix]=i;
        }
        return ans;
    } 
