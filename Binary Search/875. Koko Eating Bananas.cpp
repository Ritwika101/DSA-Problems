class Solution {
public:
    bool isPossible(int mid, vector<int>nums,int h){
        int temp_h=0;
        int i=0;
        while(i<nums.size()){
            double x = ceil((double)nums[i]/(double)mid);
            temp_h+=x;
            i++;
        }
        if(temp_h<=h)
            return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++)
            e=max(e,piles[i]);
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(mid,piles,h)){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
