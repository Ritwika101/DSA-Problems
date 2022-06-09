int getPairsCount(int nums[], int n, int target) {
        // code here
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = target - a;
            if(m.find(b)!=m.end()){
                ans+=m[b];
            }
            m[a]+=1;
        }
        return ans;  
    }
