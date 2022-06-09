vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && temp[s.top()]<=temp[i])
                s.pop();
            
            if(s.top()==-1)
                ans[i]=0;
            else
                ans[i]=s.top()-i;
            s.push(i);
        }
        
        return ans;
    }
