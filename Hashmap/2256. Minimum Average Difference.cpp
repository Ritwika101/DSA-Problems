
#define ll long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        vector<ll>prefix(nums.size(),0);
        vector<ll>postfix(nums.size(),0);
        prefix[0]=nums[0];
        postfix[n-1]=nums[n-1];
        for(ll i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(ll j=n-2;j>=0;j--){
            postfix[j]=postfix[j+1]+nums[j];
        }
        
        ll ans=INT_MAX;
        ll index=-1;
        for(int i=0;i<n;i++){
            ll pre=prefix[i];
            ll post;
            if(i==n-1)
                post=0;
            else
                post = postfix[i+1];
            ll div1=i+1, div2=n-div1;
            ll res;
            if(i==n-1){
                pre=pre/div1;
                post=0;
                res = abs(pre-post);
                if(ans>res){
                    ans=min(ans,res);
                    index=i;
                }
            }
            else{
                pre=pre/div1;
                post=post/div2;
                res = abs(pre-post);
                if(ans>res){
                    ans=min(ans,res);
                    index=i;
                }
            }
        }
        return index;
    }
};
