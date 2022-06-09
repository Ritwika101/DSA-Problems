vector<int> searchRange(vector<int>& nums, int target) {
        int left=-1,right=-1;
        int ans=-1;
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                break;
            }
            else if(target<nums[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        if(ans==-1) return {-1,-1};
        s=0,e=ans-1;
        left=ans,right=ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target<nums[mid])   
                e=mid-1;
            else if(target==nums[mid]){
                left=mid;
                e=mid-1;
            }
            else
                s=mid+1;  
        }
        s=ans+1,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target<nums[mid])
                e=mid-1;
            else if(target==nums[mid]){
                right=mid;
                s=mid+1;
            }
            else
                s=mid+1;
                
        }
        return {left,right};
    }
