vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>0){
                v.push_back(nums[i]);
                m[nums[i]]=0;
            }
            else
                m[nums[i]]++;     
        }
        return v;
    }
