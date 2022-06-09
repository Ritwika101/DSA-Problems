 
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<ll>s;
        s.push(-1);
        vector<ll>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[i]>=s.top())
                s.pop();
            ans[i]=s.top();
            s.push(arr[i]);
        }
        return ans;
    }
