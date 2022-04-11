class Solution {
public:
    int t[31][1002];
    int mod = 1e9+7;
    int solve(int n, int sum, int k){
        if(n==0 && sum==0) //all die haveto be used and the sum should come out as 0
            return 1;
        if(n==0 || sum<0)
            return 0;
        if(t[n][sum]!=-1)
            return t[n][sum];
        int ways=0;
        for(int h=1;h<=k;h++){
            ways = (ways+solve(n-1,sum-h,k))%mod;
        }
        return t[n][sum]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t,-1,sizeof(t));
        return solve(n,target,k);
    }
};
