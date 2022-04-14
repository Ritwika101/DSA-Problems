class Solution {
public:
    int atmostK(vector<int>& nums, int k){
        if(k==0)
            return 0;
        int rel=0, distinct=0, n=nums.size(),ans=0;
        unordered_map<int,int>m;
        for(int acq=0;acq<n;acq++){
            if(m[nums[acq]]==0)
                distinct+=1;
            m[nums[acq]]+=1;
            while(rel<acq && distinct>k){
                m[nums[rel]]-=1;
                if(m[nums[rel]]==0)
                    distinct-=1;
                rel+=1;
            }
            ans+=(acq-rel+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = atmostK(nums,k) - atmostK(nums,k-1);
        return x;
    }
};
