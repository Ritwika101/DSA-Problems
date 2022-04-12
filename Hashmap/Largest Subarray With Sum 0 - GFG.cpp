int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int>m;
        m[0]=-1;
        int ans=0,prefix=0;
        for(int i=0;i<n;i++){
            prefix+=a[i];
            if(m.find(prefix)==m.end())
                m[prefix]=i;
            else
                ans = max(ans,i-m[prefix]);
        }
        return ans;
    }
