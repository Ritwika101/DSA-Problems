vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++)
            m[nums1[i]]++;
        int k=0;
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]>0){
                m[nums2[i]]--;
                 nums1[k++]=nums2[i];
            }  
        }
        return vector(begin(nums1),begin(nums1)+k);
    }
