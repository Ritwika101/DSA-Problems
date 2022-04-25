
class Solution{
    public:
    int di[4] = {1,0,0,-1};
    int dj[4] = {0,-1,1,0};
    void solve(int i, int j, string& move, int n, vector<vector<int>>a, vector<string>&ans, vector<vector<int>>&vis){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n || a[i][j]==0 || vis[i][j])
            return;
        string temp="DLRU";
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newi=i+di[k];
            int newj=j+dj[k];
            if(newi>=0 && newj>=0 & newi<n && newj<n && !vis[newi][newj] && a[newi][newj]==1){
                move.push_back(temp[k]);
                solve(newi,newj,move,n,a,ans,vis);
                move.pop_back();
                
            }
            
        }
        vis[i][j]=false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector < string > ans;
        string move="";
        vector < vector < int >> vis(n, vector < int > (n, 0));
        if (m[0][0] == 1) solve(0, 0, move, n, m, ans, vis);
        return ans;
        
    }
};

