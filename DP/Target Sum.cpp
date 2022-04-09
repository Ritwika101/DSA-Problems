class Solution {
public:
    int t[21][3001];
    int solve(int n, int s, vector<int>&nums){
        if(n==0 && s<0)
            return t[n][abs(s)]=0;
	if(n==0 && s>0)
	    return t[n][s+1000]=0;
        if(n==0 && s==0)
            return t[n][s+1000]=1;
        if(s>=0 && t[n][s+1000]!=-1)
            return t[n][s+1000];
        else if(s<0 && t[n][abs(s)]!=-1 )
            return t[n][abs(s)];
        int posSign = solve(n-1,s-nums[n-1], nums);
        int negSign = solve(n-1, s+nums[n-1], nums);
        if(s>=0)
            t[n][s+1000]=posSign+negSign;
        else
            t[n][abs(s)]=posSign+negSign;
        return posSign+negSign;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(t,-1,sizeof(t));
        int s = S;
        int n = nums.size();
        return solve(n, s, nums);
        
    }
};
