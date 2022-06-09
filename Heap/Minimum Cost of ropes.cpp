long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        for(long long i=0;i<n;i++)
            pq.push(arr[i]);
        long long sum=0;
        while(pq.size()>1){
            long long res=0;
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            res = a+b;
            sum+=res;
            pq.push(res);
            
        }
        
        return sum;
    }
