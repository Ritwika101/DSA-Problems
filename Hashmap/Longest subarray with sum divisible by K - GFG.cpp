int longSubarrWthSumDivByK(int nums[], int n, int k)
{
	// Complete the function
        int prefix=0,ans=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int rem = (k + prefix%k)%k;
            if(m.find(rem)!=m.end())
                ans=max(ans,i-m[rem]);
            else
                m[rem]=i;

        }
        return ans;
    
}
