int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        while(i<=j){
            if(nums[i]==arr[i])
                i++;
            if(nums[j]==arr[j])
                j--;
            else if(nums[i]!=arr[i] && nums[j]!=arr[j])
                break;
        }
        if(i>=j)
            return 0;
        return j-i+1;
    }
