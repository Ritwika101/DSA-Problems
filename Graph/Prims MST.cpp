class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int sum = 0;
	void MST(int V, vector<bool>&vis, vector<int>&parent, vector<int>&key,vector<vector<int>> adj[]){
	    priority_queue<int, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	    pq.push({0, 0});
	    key[0] = 0;
	    parent[0] = -1;
	    while(!pq.empty()){
	        pair<int,int>x = pq.top();
	        int u = pq.top().second;
	        int w = pq.top().first;
	        pq.pop();
		      if(vis[u]) continue;
	        vis[u] =true;
	        for(auto i : adj[u]){
	            if(!vis[i[0]] && i[1] < key[i[0]]){
	                parent[i[0]] = u;
	                key[i[0]] = i[1];
	                pq.push({i[1], i[0]});
	            }
	        }
	        sum+=w;
	       
	    
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>vis(V);
        vector<int>parent(V);
        vector<int>key(V);
        for(int i=0;i<V;i++){
            vis[i]=false;
            parent[i] = -1;
            key[i] = INT_MAX;
        }
  
       MST(V, vis, parent, key,adj);
       return sum;
    }
};
