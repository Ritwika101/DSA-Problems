vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = target-nums[i];
            if(m.find(b)!=m.end()){
                res.push_back(m[b]);
                res.push_back(i);
                return res;
            }
            m[a]=i;
        }
        return res;
    }
