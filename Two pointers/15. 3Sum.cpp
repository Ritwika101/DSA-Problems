vector<vector<int>> threeSum(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int lo = i+1;
                int hi = n-1;
                int sum = 0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        vector<int>x;
                        int b = nums[lo];
                        int c = nums[hi];
                        x.push_back(nums[i]);
                        x.push_back(b);
                        x.push_back(c);
                        res.push_back(x);
                       
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        
                        lo++;
                        hi--;
                    }
                    
                    else if(nums[lo]+nums[hi]<sum)
                        lo++;
                    else 
                        hi--;
                }
            }
        }
        return res;
    }
