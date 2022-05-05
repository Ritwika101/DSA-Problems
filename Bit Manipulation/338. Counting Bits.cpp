class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        if(n==0)
            return ans;
        ans[1]=1;
        if(n==1)
            return ans;
        ans[2]=1;
        if(n==2)
            return ans;
        for(int i=3;i<=n;i++){
            if(i&(i-1)==0)
                ans[i]=1;
            else{
                if(i&1==1){
                    int prev=i>>1;
                    ans[i]=ans[prev]+1;
                }
                else{
                    int prev=i>>1;
                    ans[i]=ans[prev];
                }
            }
        }
        return ans;
    }
};
