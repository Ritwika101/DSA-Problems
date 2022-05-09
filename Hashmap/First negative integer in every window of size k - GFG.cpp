vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
    queue<long long int>q;
    for(long long int i=0;i<k-1;i++){
        if(a[i]<0)
            q.push(i);
    }
    vector<long long int>ans;
    for(long long int i=k-1;i<n;i++){
        while(!q.empty() && i-q.front()>=k)
            q.pop();
        if(a[i]<0)
            q.push(i);
        if(!q.empty())
            ans.push_back(a[q.front()]);
        else
            ans.push_back(0);
    }
    return ans;
 }
