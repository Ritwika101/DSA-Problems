

class Solution {
public:
	void dfs(int node, int parent, int& timer, vector<int>&time, vector<int>&low, vector<int>&vis, vector<vector<int>>&graph, vector<vector<int>>&ans) {
		vis[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;
        for(auto adjacent : graph[node]){
            if(parent==adjacent) continue;
            if(!vis[adjacent])
                dfs(adjacent,node,timer,time,low,vis,graph,ans);
            low[node]=min(low[node],low[adjacent]);
        }
        if(parent!=-1 && low[node]>time[parent])
            ans.push_back({parent,node});
	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
	    vector<vector<int>>graph(n);
        int timer = 1;
	    vector<int>time(n);
        vector<int>low(n);
        vector<int>vis(n);
		for(auto edge : connections) {
			graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
		}
		dfs(0,-1,timer,time,low,vis,graph,ans);
		return ans;
	}
};
