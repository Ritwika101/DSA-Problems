class Solution {
public:
    struct node{
        int parent;
        int rank;
    };
    int find(int i, vector<node>&subset){
        if(subset[i].parent!=i)
            subset[i].parent=find(subset[i].parent,subset);
        return subset[i].parent;
    }
    void unionUtil(int x, int y, vector<node>&subset){
        if(subset[x].rank > subset[y].rank){
            subset[y].parent=x;
        }
        else if(subset[x].rank < subset[y].rank){
            subset[x].parent=y;
        }
        else{
            subset[x].rank++;
            subset[y].parent=y;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i==j)
                    continue;
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }  
            }
        }
        int c=0;
        map<int,bool>vis;
        vector<node>subset(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            subset[i].parent=i;
            subset[i].rank=1;
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                int x = i;
                int y = adj[i][j];
                int px=find(x,subset);
                int py=find(y,subset);
                if(px!=py)
                    unionUtil(px,py,subset);
            }
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                int x = i;
                int y = adj[i][j];
                int px=find(x,subset);
                int py=find(y,subset);
                subset[x].parent=px;
                subset[y].parent=py;
            }
        }
        int count=0;
        for(int i=0;i<subset.size();i++){
           if(subset[i].parent==i) count++;
        }
        return count;
    }
};
