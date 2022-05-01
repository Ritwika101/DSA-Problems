int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>t(n,1);
	    vector<int>s(n,1);
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                t[i]=max(t[i],t[j]+1);
	        }
	    }
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[j]<nums[i])
	                s[i]=max(s[i],s[j]+1);
	        }
	    }
	    vector<int>result(n,0);
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        result[i]=t[i]+s[i]-1;
	        ans=max(ans,result[i]);
	    }
	    return ans;
	}
