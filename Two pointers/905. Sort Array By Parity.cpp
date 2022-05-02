vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int k=n-1;
        int i=0, j=n-1;
        while(i<j){
            if(nums[i]%2!=0 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i]%2!=0){
                while(j>=0 && nums[j]%2!=0 )
                    j--;
                if(i>=j)
                    break;
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[j]%2==0){
                while(i<=n-1 && nums[i]%2==0)
                    i++;
                if(i>=j)
                    break;
                swap(nums[i],nums[j]);
                i++;
                j--;
                
            }
            else{
                i++;
                j--;
            }      
        }
        return nums;
    }
