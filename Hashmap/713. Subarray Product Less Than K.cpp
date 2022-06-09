int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int rel=0;
        int product=1;
        int ans=0;
        if(k==0)
            return 0;
        for(int acq=0;acq<nums.size();acq++){
            product*=nums[acq];
            while(rel<acq && product>=k){
                product/=nums[rel];
                rel++;
            }
            if(product>=k)
                continue;
            ans+=(acq-rel+1);
        }
        return ans;
    }
