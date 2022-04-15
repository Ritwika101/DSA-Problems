int subarraysDivByK(vector<int>& nums, int k) {
        int prefix=0,ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int rem = (k + prefix%k)%k;
            if(m.find(rem)!=m.end())
                ans+=m[rem];
            m[rem]+=1;

        }
        return ans;
    }
