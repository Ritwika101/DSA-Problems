   int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>next(n);
        vector<int>prev(n);
        prev[0]=1;
        next[n-1]=1;
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
                s.pop();
            if(s.top()==-1) 
                next[i]=n-i;
            else 
                next[i]=s.top()-i;
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>arr[i])
                s.pop();
            if(s.top()==-1)
                prev[i]=i+1;
            else
                prev[i]=i-s.top();
            s.push(i);
        }
        int sum=0;
        for(ll i=0;i<n;i++){
            ll curr=prev[i]%mod;
            curr=(curr%mod * next[i]%mod)%mod;
            curr=(curr%mod * arr[i]%mod)%mod;
            sum=(sum%mod + curr%mod)%mod;
        }
        return sum;
    }
