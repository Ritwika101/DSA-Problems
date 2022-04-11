vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto x : m){
            pq.push({x.second,x.first});
        }
            
        vector<int>res;
        int j = 0;
        
        while(j<k && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            j++;
        }
        return res;
        
    }
