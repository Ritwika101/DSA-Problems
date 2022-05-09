int minSubArrayLen(int target, vector<int>& nums) {
        if(target==0)
            return 0;
        int ans=INT_MAX, n=nums.size();
        int rel=0, count=0, sum=0;
        for(int acq=0;acq<n;acq++){
            if(nums[acq]+sum <target)
            {
                sum+=nums[acq];
                count+=1;
            }
            else if(nums[acq]+sum>=target){
                sum+=nums[acq];
                count+=1;
                ans=min(ans,count);
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
