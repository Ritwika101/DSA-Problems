int minDeletions(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        int count=0;
        priority_queue<int>pq;
        for(auto x:m){
            if(x.second>0)
            pq.push(x.second);
        }
        while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            if(top==pq.top()){
                if(top-1>0){
                top-=1;    
                pq.push(top);}
                count++;
            }
        }
        return count;
    }
