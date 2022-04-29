int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<int>t(n,0);
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++)
            nums[i]={ages[i],scores[i]};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
            t[i]=nums[i].second;     
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i].second>=nums[j].second){    
                    t[i]=max(t[i],t[j]+nums[i].second);
                }
            }
        }   
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(t[i],ans);
        return ans;
    }
