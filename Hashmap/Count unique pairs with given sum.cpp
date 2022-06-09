int getPairsCount(int nums[], int n, int target) {
        // code here
        vector<bool>vis(n,false);
        int count=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int a=nums[i];
	      int b=target-a;
	      if(m.find(b)!=m.end() && !vis[a] && !vis[b}]){
		      count++;
		      vis[a]=true;
		      vis[b]=true;
	      }
	      m[a] = 1;
	  }
    return count;     
  }
