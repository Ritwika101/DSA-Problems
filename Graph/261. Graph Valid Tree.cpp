
class Solution {
public:
    struct node{
        int parent;
        int rank;
    };
    
    int find(int i, vector<node>&subset){
        if(subset[i].parent!= i)
            subset[i].parent = find(subset[i].parent,subset);
        
        return subset[i].parent;    
    }
    void unionUtil(int x, int y, vector<node>&subset){
        if(subset[x].rank> subset[y].rank){
            subset[y].parent = x;
        }
        else if(subset[x].rank< subset[y].rank){
            subset[x].parent= y;
        }
        else{
            subset[y].parent= x;
            subset[x].rank++;
        }
        
    }
    bool disjointSet(vector<vector<int>>&edges, vector<node>&subset){
        for(auto p : edges){
            int x = find(p[0],subset);
            int y = find(p[1],subset);
            if(x == y) return false;
            unionUtil(x, y,subset);
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<node>subset(n);
        for(int i=0;i<n;i++){
            subset[i].parent=i;
            subset[i].rank=0;
        }
        if(!disjointSet(edges,subset))
            return false;
        int parent=INT_MAX;
        for(int i=0;i<n;i++){
            int p = find(i,subset);
            if(i==0){
                parent=p;
                continue;
            }
            if(i>0 && p!=parent)
                return false;
        }
        return true;
    }
};
