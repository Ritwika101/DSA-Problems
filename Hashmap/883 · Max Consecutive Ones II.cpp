int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        int count1=0,count0=0, ans=0;
        int rel=0;
        for(int acq=0;acq<nums.size();acq++){
            if(nums[acq]==0)
                count0+=1;
            else
                count1+=1;
            while(rel<acq && count0>1)
            {
                if(nums[rel]==0)
                    count0-=1;
                else    
                    count1-=1;
                rel+=1;
            }
            ans=max(ans,acq-rel+1);
        }
        return ans;
    }

