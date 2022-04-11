ll solve(int n, int sum, vector<int>nums, vector<vector<ll>>&t){
    if(n==0 && sum!=0)
        return t[n][sum]=0;
    if(sum==0)
        return t[n][sum]=1;
    if(t[n][sum]!=-1)
        return t[n][sum];
    if(nums[n-1]<=sum)
        return t[n][sum] = solve(n,sum-nums[n-1],nums,t) + solve(n-1,sum,nums,t);
    else
        return t[n][sum] = solve(n-1,sum,nums,t);
        
}
long long int count(long long int n)
{
    vector<int>nums;
    vector<vector<ll>>t(4, vector<ll>(n+1, -1));
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(10);
    return solve(3,n,nums,t);
    
}
