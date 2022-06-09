
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        for(auto x: m)
            pq.push(x.second);
        int ans=0;
        while(k>0){
            if(pq.empty()) break;
            if(k-pq.top()<0){
                k=0;
                int temp = pq.top();
                pq.pop();
                temp-=k;
                pq.push(temp);
            }
            else{
                k-=pq.top();
                pq.pop();
            }  
        }
        while(!pq.empty()){
            pq.pop();
            ans++;
        }
        return ans;
    }
