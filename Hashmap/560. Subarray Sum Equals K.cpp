int subarraySum(vector<int>& nums, int k) {
        int prefix=0, ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(m.find(prefix-k)!=m.end()){
                ans+=m[prefix-k];
            }
            m[prefix]+=1;
        }
        return ans;
    }
