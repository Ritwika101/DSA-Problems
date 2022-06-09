class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1) 
            return findMedianSortedArrays(nums2,nums1);
        int total=n1+n2;
        int left=0;
        bool flag=false;
        if(total%2 == 0){
            left=total/2;
            flag=true;
        }   
        else
            left=(total+1)/2;
        int low=0,high=n1;
        double median=0.0;
        while(low<=high){
            double mid=low+(high-low)/2;
            double cut1=mid;
            double cut2=left-mid;
            double l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cut1>0)
                l1=nums1[cut1-1];
            if(cut2>0)
                l2=nums2[cut2-1];
            if(cut1<n1)
                r1=nums1[cut1];
            if(cut2<n2)
                r2=nums2[cut2];
            if(l1<=r2 && l2<=r1)
            {
                if(total%2==0)
                {
                    median =  (max(l1,l2)+min(r1,r2));
                    median=median/2.0;
                    return median;
                }
                else{
                    median =  max(l1,l2);
                    return median;
                }
            }
            else if(l1>r2){
                    high=cut1-1;
                }
            else if(l2>r1) {
                    low=cut1+1;
                }
            
        }
        return 0.0;
    }
};
