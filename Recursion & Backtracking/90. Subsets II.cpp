void solve(int i, int n, int sum, vector<int>&output,vector<vector<int>>&res,vector<int>nums){
           res.push_back(output);
           for(int k=i;k<n;k++){
            if(k>i && nums[k]==nums[k-1])
                continue;
            output.push_back(nums[k]);
            solve(k+1,n,sum+nums[k],output,res,nums);
            output.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,0,output,res,nums);
        return res;
    }
