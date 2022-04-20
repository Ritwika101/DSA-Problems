void subset(int i,int n,vector<int>& nums,vector<int>& output,vector<vector<int>>&res){
        if(i==n)
        {
            res.push_back(output);
            return;
        }
        output.push_back(nums[i]);
        subset(i+1,n,nums,output,res);
        output.pop_back();
        subset(i+1,n,nums,output,res);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>res;
        int n=nums.size();
        int i=0;
        subset(i,n,nums, output, res);
        return res;
    }
