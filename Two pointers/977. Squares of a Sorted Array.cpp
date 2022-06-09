vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result(nums.size());
        int i=0,j=nums.size()-1;
        int index=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])<abs(nums[j]))
                result[index]=nums[j--];
            
            else
                result[index]=nums[i++];
            result[index]=result[index]*result[index];
            index--;
        }
        return result;
    }
