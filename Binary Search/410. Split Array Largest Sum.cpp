class Solution {
public:
    bool isValid(int mid, vector<int>&nums, int m, int& ans){
        int sum = 0;
        int maxSum = 0;
        int pieces = 1;
        int counter = mid;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=counter){
                sum+=nums[i];
                counter-=nums[i];
                maxSum=max(maxSum, sum);
            }
            else{
                pieces++;
                counter=mid;
                sum = 0;
                sum+=nums[i];
                counter-=nums[i];
                maxSum=max(maxSum, sum);  
            }
        }
        if(pieces<=m){
            ans=min(ans,maxSum);
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int min = INT_MIN, max = 0;
        int sum = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            min = nums[i]>min?nums[i] : min;
        }
        max=sum;
        int s=min, e=max;
        int ans = INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isValid(mid,nums,m,ans)){
                e = mid-1;
            }
            else{
                s=mid+1;
            }
                
        }
        return ans;
    }
};
