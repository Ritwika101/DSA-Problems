class Solution {
public:
    int t[20002];
    int solve(int i, int maxnum, vector<int>freq){
        if(i>maxnum)
            return t[i] = 0;
        if(t[i]!=-1)
            return t[i];
        int consider = i*freq[i] + solve(i+2,maxnum,freq);
        int noconsider = solve(i+1,maxnum,freq);
        return t[i] = max(consider,noconsider);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            maxnum = max(maxnum,nums[i]);
            minnum = min(minnum,nums[i]);
        }
            
        vector<int>freq(maxnum+1,0);
        
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        //sort(nums.begin(),nums.end());
        return solve(minnum,maxnum,freq);
        
    }
};
