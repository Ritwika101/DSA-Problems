int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0;
        int rel=0;
        int n=nums.size();
        int ans=0;
        int maxsum=0;
        for(int acq=0;acq<n;acq++){
            while(rel<acq && m[nums[acq]]!=0){
                m[nums[rel]]--;
                sum-=nums[rel];
                rel++;   
            }
            m[nums[acq]]++;
            sum+=nums[acq];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
