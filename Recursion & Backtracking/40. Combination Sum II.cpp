void solve(int i, int n, int target, vector<int>&output,vector<vector<int>>&res,vector<int>nums){
        if(target==0){
            res.push_back(output);
            return;
        }
        if(i==n)
            return;
        int j=i;
        for(int k=i;k<n;k++){
            if(k>i && nums[k]==nums[k-1])
                continue;
            if(nums[k]>target)
                break;
            output.push_back(nums[k]);
            solve(k+1,n,target-nums[k],output,res,nums);
            output.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates.size(),target,output,res,candidates);
        
        
        return res;
    }
