
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,1);
        vector<int>count(n,1);
        count[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        count[i]=count[j];
                    }
                    else if(t[i]==t[j]+1)
                        count[i]+=count[j];
                }
            }
            ans=max(ans,t[i]);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(t[i]==ans)
                cnt+=count[i];
        }
        return cnt;
    }
};
