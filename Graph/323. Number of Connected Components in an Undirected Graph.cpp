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
    void disjointSet(vector<vector<int>>&edges, vector<node>&subset){
        for(auto p : edges){
            int x = find(p[0],subset);
            int y = find(p[1],subset);
            if(x != y)
                unionUtil(x, y,subset);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<node>subset(n);
        for(int i=0;i<n;i++){
            subset[i].parent=i;
            subset[i].rank=0;
        }
        disjointSet(edges,subset);
        unordered_map<int,int>m;
        int connected=0;
        for(int i=0;i<n;i++){
            int parent = find(i,subset);
            if(m.find(parent)==m.end())
            {
                connected++;
                m[parent]++;
            }
        }
        return connected;
        
    }
};
