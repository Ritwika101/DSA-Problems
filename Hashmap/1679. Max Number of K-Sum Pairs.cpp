int maxOperations(vector<int>& nums, int k) { 
        int n=nums.size();
        int count=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int find = k-nums[i];
            if(m[find]>0)
            {
                m[find]-=1;
                count++;
            }
            else
                m[nums[i]]++;
        }
        return count;
    }
