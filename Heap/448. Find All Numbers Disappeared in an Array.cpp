vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        int n = nums.size();
        int l=n;
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++)
            pq.push(nums[i]);
        while(!pq.empty()){
            int top = pq.top();
            if(l==top){
               pq.pop();
               l-=1;
            }      
            else if(l<top)
                pq.pop();
            else if(l>top){
                res.push_back(l);
                l-=1;
            }
        }
        if(l>=1){
            while(l>=1){
                res.push_back(l);
                l-=1;
            }
        }
        
        return res;
    }
