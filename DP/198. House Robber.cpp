int solve(int i, int n, vector<int>&v, vector<int>nums){
        if(i>=n)
            return v[key] = 0;
        int key = i;
        if(v[key]!=INT_MIN)
            return v[key];
        int rob = solve(i+2,n,v,nums)+nums[i];
        int norob = solve(i+1,n,v,nums);
        return v[i]=max(rob,norob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,INT_MIN);
        return solve(0,n,v,nums);
        
    }
