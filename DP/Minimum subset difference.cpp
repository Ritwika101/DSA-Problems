int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0,s;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    s=sum/2;
	    int t[n+1][s+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=s;j++){
	            if(i==0)
	                t[i][j]=0;
	            if(j==0)
	                t[i][j]=1;
	        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=s;j++){
	            if(arr[i-1]<=j)
	                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	            else
	                t[i][j] = t[i-1][j];
	        }
	    }
	    for(int i=s;i>=0;i--){
	        if(t[n][i]>=1){
	            int x = 2*i;
	            int ans = sum-x;
	            return ans;
	        }
	            
	    }
	    return 0;
	} 
