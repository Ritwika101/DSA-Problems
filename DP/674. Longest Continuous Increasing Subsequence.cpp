int findLengthOfLCIS(vector<int>& nums) {
        int count=1,ans=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                count+=1;
                ans=max(ans,count);
            }
            else{
                count=1;
            }
        }
        return ans;
    }
