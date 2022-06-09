 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ll n1=nums1.size(), n2=nums2.size();
        vector<ll>res(n2,-1);
        stack<ll>s;
        s.push(-1);
        for(int i=n2-1;i>=0;i--){
            while(s.top()!=-1 && s.top()<=nums2[i])
                s.pop();
            res[i]=s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<n1;i++){
            auto index=find(nums2.begin(),nums2.end(),nums1[i]);
            if(index==nums2.end())
                nums1[i]=-1;
            else
                nums1[i]=res[index-nums2.begin()];
        }
        return nums1;
    }
