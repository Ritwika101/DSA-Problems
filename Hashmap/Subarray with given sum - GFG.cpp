vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        ll sum=0;
        int rel=0;
        vector<int>path;
        for(int acq=0;acq<n;acq++){
            sum+=arr[acq];
            while(rel<acq && sum>s){
                sum-=arr[rel];
                rel++;
            }
            if(sum==s){
                vector<int>ans(2,0);
                ans[0]=rel+1;
                ans[1]=acq+1;
                return ans;
            }
            
        }
        return {-1};
    }
