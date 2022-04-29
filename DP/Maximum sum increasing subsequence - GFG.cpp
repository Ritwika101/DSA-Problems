
int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    int ans=0;
	    vector<int>t(n,0);
	    t[0]=nums[0];
	    ans=t[0];
	    for(int i=0;i<n;i++)
	        t[i]=nums[i];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i]){
	                t[i]=max(t[i],t[j]+nums[i]);
	            }
	            
	        }
	        ans=max(ans,t[i]);
	    }
	   return ans;
	    
	}
