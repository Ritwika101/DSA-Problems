class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1);
        map<int,int>prefix;
        map<int,int>postfix;
        
        int pre=1,post=1;
       
        for(int i=0;i<nums.size();i++){
            pre*=nums[i];
            prefix[i]=pre;
            if(i>0)
                res[i]*=prefix[i-1];
            
        }
        for(int i=n-1;i>-1;i--){
            post*=nums[i];
            postfix[i]=post;
            if(i<n-1)
                res[i]*=postfix[i+1];
        }
        
        
        return res;
        
    }
};
