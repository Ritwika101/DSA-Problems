int maxSubArray(vector<int>& nums) {
        vector<int>t(nums.size(),0);
        t[0]=nums[0];
        int ans=t[0];
        for(int i=1;i<nums.size();i++){
            t[i]=max(t[i-1]+nums[i],nums[i]);
            ans=max(ans,t[i]);
        }
        return ans;  
            
    }
