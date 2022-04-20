void solve(int i, int n, vector<int>nums,vector<int>&output, vector<vector<int>>&res, int sum, int target){
        if(i==n && sum==target){
            res.push_back(output);
            return;
        }
        if(i==n)
            return;
        if(nums[i]+sum<=target){
            output.push_back(nums[i]);
            sum+=nums[i];
            solve(i,n,nums,output,res,sum,target);
            output.pop_back();
            sum-=nums[i];
        }
        solve(i+1,n,nums,output,res,sum,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>output;
        solve(0,candidates.size(),candidates,output,res,0,target);
        return res;
    }
