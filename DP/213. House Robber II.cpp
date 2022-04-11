class Solution {
public:
    int t[102];
    int solve(vector<int>& nums,int i, int n){
        if(i>n)
            return t[i] = 0;
        if(t[i]!=-1)
            return t[i];
        return t[i]=max((solve(nums,i+2, n)+nums[i]), solve(nums,i+1, n));
        
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n<=0)
            return 0;
        int x = solve(nums,0,n-2);
        memset(t,-1,sizeof(t));
        int y = solve(nums,1,n-1);
        return max(x,y);
    }
};
