struct node{
    
    int parent;
    int rank;
};
class Solution {
public:
    int find(int i, vector<node>&subset){
        if(i!=subset[i].parent){
            subset[i].parent = find(subset[i].parent,subset);
        }
        return subset[i].parent;
    }
    void makeUnion(int x, int y, vector<node>&subset){
        if(subset[x].rank > subset[y].rank){
            subset[y].parent=x;
        }
        else if(subset[x].rank < subset[y].rank){
            subset[x].parent=y;
        }
        else{
            subset[y].parent=x;
            subset[x].rank+=1;
        }
    }
    void unionUtil(int x, int y,vector<node>&subset){
        int px = find(x,subset);
        int py = find(y,subset);
        if(px!=py){
            makeUnion(px,py,subset);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>m;
        int n = s.length();
        string smallest(n,'.');
        vector<node>subset;
        for(int i=0;i<n;i++){
            node temp;
            temp.parent = i;
            temp.rank = 1;
            subset.push_back(temp);
        }
        for(int i=0;i<pairs.size();i++){
            int x=pairs[i][0];
            int y=pairs[i][1];
            unionUtil(x,y,subset);
        }
        for(int i=0;i<subset.size();i++){
            int p = find(i,subset);
            m[p].push_back(i);
        }
     
        for(auto x : m){
            vector<char>chars;
            for(int i=0;i<x.second.size();i++)
                chars.push_back(s[x.second[i]]);
            sort(x.second.begin(),x.second.end());
            sort(chars.begin(),chars.end());
            for(int i=0;i<x.second.size();i++){
                smallest[x.second[i]]=chars[i];
            }
        }
        return smallest;
    }
};
