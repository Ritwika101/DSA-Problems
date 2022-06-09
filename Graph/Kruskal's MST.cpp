#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<int, list<pair<int, int>>>adj;
vector<pair<int, pair<int, int>>>pairs;
int weight = 0;
void addEdge(int u, int v, int w, int dir){
    pairs.push_back({w,{u,v}});
}

struct node{
    int parent;
    int rank;
};
int find(int i, vector<node>&subset){
    if(subset[i].parent!=i){
        subset[i].parent = find(subset[i].parent, subset);
    }
    return subset[i].parent;
}
void makeUnion(int x, int y, vector<node>&subset){
    if(subset[x].rank > subset[y].rank){
        subset[y].parent = x;
    }
    else if(subset[y].rank > subset[x].rank){
        subset[x].parent = y;
    }
    else{
        subset[y].parent = x;
        subset[x].rank++;
    }
}
void kruskals(vector<pair<int, pair<int, int>>>&pairs, vector<node>&subset,vector<pair<int, pair<int, int>>>&result ){
    sort(pairs.begin(), pairs.end());
    for(auto x :  pairs){
        //bool flag = isCycle(x.second.first, x.second.second);
        int u = find(x.second.first, subset);
        int v= find(x.second.second, subset);
        if(u != v){
            result.push_back({x.first, {x.second.first, x.second.second}});
            weight+=x.first;
            makeUnion(u, v, subset);   
        }
        
    }
    for(auto x: result){
            cout<<x.second.first<<" -> "<<x.second.second<<" Weight = "<<x.first<<endl;
        }
}
int main(){
    int v = 8, e = 11;
    vector<node>subset(v);
    for(int i=0;i<v;i++){
        subset[i].parent = i;
        subset[i].rank = 0;
    }
    addEdge(1, 2, 8, 0);
    addEdge(1, 3, 4, 0);
    addEdge(1, 4, 2, 0);
    addEdge(2, 3, 10, 0);
    addEdge(3, 4, 5, 0);
    addEdge(3, 5, 17, 0);
    addEdge(4, 5, 14, 0);
    addEdge(3, 6, 11, 0);
    addEdge(5, 6, 5, 0);
    addEdge(6, 7, 1, 0);
    addEdge(5, 7, 9, 0);
    vector<pair<int, pair<int,int>>>result;
    kruskals(pairs, subset, result);
    cout<<weight;

}
