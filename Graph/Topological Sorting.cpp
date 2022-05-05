class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j : adj[i]){
	            indegree[j]++;
	            
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	          {  q.push(i);
	            }
	    }
	    vector<int>res;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        res.push_back(u);
	        for(auto v : adj[u]){
	            indegree[v]--;
	            if(indegree[v]==0)
	                q.push(v);
	        }
	    }
	    
	    return res;
	    
	    
	}
};
