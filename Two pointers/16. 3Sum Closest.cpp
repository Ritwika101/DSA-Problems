int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX;
        int n=nums.size();
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int a = nums[i];
            int sum = target-a;
            int lo=i+1,hi=n-1;
            while(lo<hi){
                int b = nums[lo];
                int c = nums[hi];
                int new_sum=b+c;
                int new_diff = abs(target-a-b-c);
                if(sum==new_sum)
                    return new_sum+a;
                else{
                    if(diff>=new_diff){
                        ans=new_sum+a;
                        diff = min(diff,new_diff);
                    }
                    if(new_sum<sum)
                        lo++;
                    else
                        hi--;
                
                }  
            }
        }
        return ans;
    }
