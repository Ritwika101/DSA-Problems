bool dfsCycle(int i, vector<int>&vis, vector<int>&rec, vector<int>adj[]){
        vis[i]=true;
        rec[i]=true;
        for(auto x : adj[i]){
            if(!vis[x]){
                if(dfsCycle(x,vis,rec,adj))
                    return true;
            }
            else{
                if(rec[x])
                    return true;
            }
        }
        rec[i] = false;
        return false;
        
    }
	bool isCyclic(int n, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int>vis(n,0);
    		vector<int>rec(n,0);
	   	for(int i=0;i<n;i++){
	   	    if(!vis[i]){
	            if(dfsCycle(i,vis,rec,adj))
	                return true;
	   	    }
	    }
	    return false;
	}
