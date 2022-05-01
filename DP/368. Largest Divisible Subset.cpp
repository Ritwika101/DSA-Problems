#define ll long long
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        if(n<=0)
            return {};
        if(n==1)
            return nums;
        unordered_map<int,int>m;
        m[0]=0;
        vector<ll>t(n,1);
        ll ans=1, index=0;
        for(ll i=1;i<n;i++){
            m[i]=i;
            for(ll j=0;j<i;j++){
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0)
                {
                    if(t[i]<t[j]+1){
                       t[i]=max(t[i],t[j]+1);
                        m[i]=j;     
                    }  
                }
            }
            if(ans<t[i]){
                ans=t[i];
                index=i; 
            }
        }
        vector<int>result;
        ll k=index;
        
        while(m[k]!=k){
            result.push_back(nums[k]);
            k=m[k];
        }
        result.push_back(nums[k]);
        return result;
    }
};
