class Solution {
public:
    int t[101][101][101];
    int solve(vector<vector<int>>& costs, int i, int n, int a, int b)
    {
        if(i==n && a==0 && b==0)
            return t[i][a][b] = 0;
        if(a==0 && b==0)
             return t[i][a][b] = 0;
        if(t[i][a][b]!=-1)
            return t[i][a][b];
        if(a>0 && b>0){
            return  t[i][a][b] = min( (costs[i][0]+solve(costs,i+1,n,a-1,b)), (costs[i][1]+solve(costs,i+1,n,a,b-1)) );
        }
        else if(a>0)
            return  t[i][a][b] = (costs[i][0]+solve(costs,i+1,n,a-1,b));
        else
            return  t[i][a][b] = (costs[i][1]+solve(costs,i+1,n,a,b-1));
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
       
        int n = costs.size();
        memset(t,-1,sizeof(t));
        return solve(costs,0,n,n/2,n/2);
    }
};
