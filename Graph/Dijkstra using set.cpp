#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
vector<vector<pair<int, int>>> adj;
void addEdge(int u, int v, int w, bool dir){
    adj[u].push_back({v,w});
    if(!dir)
        adj[v].push_back({u,w});
}
void Dijkstra(int V, vector<bool>&vis, vector<int>&parent, vector<int>&dist,vector<vector<pair<int, int>>> adj){

	    set<pair<int, int> >s;
            s.insert({0,0});
            dist[0] = 0;
	    while(!s.empty()){
		    pair<int,int> p = *(s.begin());
        int w = p.first; //total cost till u
        int u = p.second;
		    if(vis[u])
			     continue;
		    vis[u] = 1;
        s.erase(s.begin());
        for(auto x : adj[u]){
           if(dist[x.first] > w+x.second&& !vis[x.first]){
                auto f = s.find({dist[x.first], x.first});
                if(f!=s.end())
                   s.erase(f);
                dist[x.first] = w+x.second;
                s.insert({dist[x.first], x.first});
                parent[x.first] = u;
			    }
		    }      
	   }
}
int main(){
    int V = 8;
    adj.resize(V);
    addEdge(0, 1,3, 0);
    addEdge(0, 3,14, 0);
    addEdge(1, 2,8, 0);
    addEdge(1, 3,10, 0);
    addEdge(2, 5,2, 0);
    addEdge(2, 7,15, 0);
    addEdge(3, 4,6, 0);
    addEdge(3, 5,5, 0);
    addEdge(4, 5,4, 0);
    addEdge(5, 6,9, 0);
    
  
    //Printing path
    for(int j=0;j<V;j++){
        int k = j;
        while(true){
            if(k == -1)
                break;
            cout<<k<<"---";
            k = parent[k];
            
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<V;i++){
       cout<<i<<" = "<<dist[i]<<endl;
    }
   
}
