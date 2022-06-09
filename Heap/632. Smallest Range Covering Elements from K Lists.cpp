vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pi,vector<pi>, greater<pi>>pq;
        int minNum=INT_MAX, maxNum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minNum = min(minNum,nums[i][0]);
            maxNum=max(maxNum,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        int range=INT_MAX;
        range=maxNum-minNum;
        vector<int>ans(2,INT_MAX);
        ans[0]=minNum;
        ans[1]=maxNum;
        while(true){
            auto p = pq.top();
            int smallest = p.first;
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            
            if(j==nums[i].size()-1) break;
            if(maxNum<nums[i][j+1]) maxNum = nums[i][j+1]; 
            pq.push({nums[i][j+1], {i,j+1}});
            minNum=pq.top().first;
            if(range>maxNum-minNum){
                ans[0]=minNum;
                ans[1]=maxNum;
                range = min(range,maxNum-minNum);
            }
           
        }
        return ans;
    }
