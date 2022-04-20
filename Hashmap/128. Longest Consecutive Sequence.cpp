int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int prev=INT_MIN;
        sort(nums.begin(),nums.end());
        int ans=1, result=0;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        for(int i=1;i<n;i++){   //0 0 1 2 3 4 5 6 7 8
            if(nums[i]==nums[i-1]+1){
                ans+=1;
            } 
            else if(nums[i]==nums[i-1])
                continue;
            else{
                result=max(result,ans);
                ans=1;
            }        
        }
        result=max(result,ans);
        return result;
    }

