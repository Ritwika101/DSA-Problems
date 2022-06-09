class Solution {
public:
    ll sumSubarrayMins(vector<int>& arr) {
        ll n=arr.size();
        vector<ll>next(n);
        vector<ll>prev(n);
        prev[0]=1;
        next[n-1]=1;
        stack<ll>s;
        s.push(-1);
        for(ll i=n-1;i>=0;i--){
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
        for(ll i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>arr[i])
                s.pop();
            if(s.top()==-1)
                prev[i]=i+1;
            else
                prev[i]=i-s.top();
            s.push(i);
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll curr=prev[i];
            curr=(curr * next[i]);
            curr=(curr * arr[i]);
            sum=(sum + curr);
        }
        return sum;
    }
    ll sumSubarrayMaxs(vector<int>& arr) {
        ll n=arr.size();
        vector<ll>next(n);
        vector<ll>prev(n);
        prev[0]=1;
        next[n-1]=1;
        stack<ll>s;
        s.push(-1);
        for(ll i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]<=arr[i])
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
        for(ll i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]<arr[i])
                s.pop();
            if(s.top()==-1)
                prev[i]=i+1;
            else
                prev[i]=i-s.top();
            s.push(i);
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll curr=prev[i];
            curr=(curr * next[i]);
            curr=(curr * arr[i]);
            sum=(sum + curr);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        ll sum1 = sumSubarrayMaxs(nums);
        ll sum2 = sumSubarrayMins(nums);
        return sum1-sum2;
    }
};
