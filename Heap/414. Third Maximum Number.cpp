 int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0];
        int c=INT_MIN;
        if(n==2) return max(nums[0],nums[1]);
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(c<nums[i])
                c=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()) continue;
            m[nums[i]]++;
            if(pq.size()<3)
                pq.push(nums[i]);
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        if(pq.size()<3) return c;
        else return pq.top();
    }

