void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpt = 0;
        bool flag=false;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
                breakpt=i;
                flag=true;
                break;
                
            }
        }
        if(!flag)
        {
            sort(nums.begin(),nums.end());
            return;
        }
            
        else{
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[breakpt])
                {
                    swap(nums[i],nums[breakpt]);
                    reverse(nums.begin()+breakpt+1,nums.end());
                    break;
                }
            }
            return;
        }
    }
