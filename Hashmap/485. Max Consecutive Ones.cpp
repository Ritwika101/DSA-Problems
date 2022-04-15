int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                x++;
            }
            else if(nums[i]==0){
                c = max(c,x);
                x = 0;
            }
                
        }
        c = max(c,x);
        return c;
    }
