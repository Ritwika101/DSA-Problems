#define ll long long int
class Solution {
public:
    int mod = 1e9+7;
     int threeSumMulti(vector<int>& nums, int target) {
         ll count = 0;
         unordered_map<int,ll>m;
         for(auto x : nums)
             m[x]++;
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int lo = i+1;
                int hi = n-1;
                int sum = target-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                
                        if(nums[lo]==nums[hi]&& nums[lo] == nums[i]){
                            count=count%mod;
                            ll add = ((m[nums[i]]*(m[nums[i]]-1)*(m[nums[i]]-2))/6)%mod;   //freqC3 = freq*(freq-1)*(freq-2)/6
                            count+=add;
                        }
                            
                        else if(nums[i]==nums[lo] && nums[i]!=nums[hi])
                        {
                            count=count%mod;
                            ll add = ((m[nums[i]]*(m[nums[i]]-1)*m[nums[hi]])/2)%mod;    //freqC2 = freq*(freq-1)/2
                            count+=add;
                        }
                        else if(nums[lo]==nums[hi] && nums[i]!=nums[hi])
                        {
                            count=count%mod;
                            ll add=((m[nums[lo]]*(m[nums[lo]]-1)*m[nums[i]])/2)%mod;
                            count+=add;
                        }
            
                        else if(nums[i]<nums[lo] && nums[lo]<nums[hi])
                        {
                            count=count%mod;
                            ll add=(m[nums[i]]*m[nums[lo]]*m[nums[hi]])%mod;
                            count+=add;
                        }
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        
                        lo++;
                        hi--;
                    }
                    
                    else if(nums[lo]+nums[hi]<sum)
                        lo++;
                    else 
                        hi--;
                }
            }
        }
        return count;
     }
};
