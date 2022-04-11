
bool canJump(vector<int>& nums) {
        int m = INT_MIN;
        if(nums.size()<=1)
            return true;
        int x = nums[0]+0;
        for(int i=1;i<nums.size();i++){
            if(x>=i){
                 x = max(x,i+nums[i]);
            }
            else
                return false;
        }
        return true;
    }
