int findDuplicate(vector<int>& nums) {
        int dup=-1;
        for(int i=0;i<nums.size();i++){
           if(nums[abs(nums[i])]<0){
                    dup = abs(nums[i]);
                    break;
           }
            else
                nums[abs(nums[i])]*=(-1);
        }
        return dup;
    }
