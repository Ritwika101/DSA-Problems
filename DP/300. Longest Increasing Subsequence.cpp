int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,1);
        t[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                    ans=max(ans,t[i]);
                }
            }
        }
        return ans;
        
    }
