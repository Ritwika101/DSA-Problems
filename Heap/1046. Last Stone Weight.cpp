int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int i=n-1;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        while(pq.size()>1){
           
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x==y){
                continue;
            }
            else{
                int temp=y-x;
                pq.push(temp);
            }   
        }
        if(pq.size()==0)
            return 0;
        else
            return pq.top();
        
    }
