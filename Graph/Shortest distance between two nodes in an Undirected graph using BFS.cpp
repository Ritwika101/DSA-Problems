#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
bool BFS(vector<int> adj[], int src, int dest, int v,
         vector<int>&pred, vector<int>&dis, vector<bool>&vis)
{
        queue<int>q;
        q.push(src);
        vis[src] = true;
        dis[src] = 0;
        pred[src] = -1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                if(!vis[adj[u][i]]){
                    vis[adj[u][i]]=true;
                    dis[adj[u][i]] = dis[u]+1;
                    pred[adj[u][i]] = u;
                    q.push(adj[u][i]);
                }
                if(adj[u][i]==dest)
                    return true;
            }
            
        }
        return false;
}
void printShortestDistance(vector<int> adj[], int src,
                           int dest, int v)
{
    vector<int>pred(v);
    vector<int>dis(v);
    vector<bool>vis(v);
    if(BFS(adj,src,dest,v,pred,dis,vis)==false)
        cout<<"No edge connecting them";
    else{
    cout<<"Distance = "<<dis[dest]<<endl<<"Path = ";
    vector<int>path;
    path.push_back(dest);
    path.push_back(pred[dest]);
    int x = pred[dest];
    while(pred[x]!=-1){
       path.push_back(pred[x]);
       x = pred[x];
    
    }
    for(int i=path.size()-1;i>=0;i--)
        cout<<path[i]<<" ";
    }
}
int main()
{
    int v = 8;
    vector<int> adj[v];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    //add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 3, dest = 2;
    printShortestDistance(adj, source, dest, v);
    return 0;
}
