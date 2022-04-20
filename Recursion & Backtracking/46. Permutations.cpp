
void solve(vector<int>& nums, vector<vector<int>>&ans, int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }   
        
        for(int k=i;k<nums.size();k++){
            swap(nums[i],nums[k]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        solve(nums, ans, i);
        return ans;
    }
