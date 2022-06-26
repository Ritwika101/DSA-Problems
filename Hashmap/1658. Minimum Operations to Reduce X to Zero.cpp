int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int totalsum=0;
        int temp=-x;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
            temp+=nums[i];
        }
        if(temp==0) return n;    
        int target=totalsum-x;
        int prefix=0;
        int ans=INT_MIN;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(m.find(prefix-target)!=m.end()){
                ans=max(ans,i-m[prefix-target]);
            }
                
            if(m.find(prefix)==m.end())
                m[prefix]=i;
        }
        if(ans==INT_MIN) return -1;
        return n-ans;
    }
