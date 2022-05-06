vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x)
    {
        vector<pair<int,int>>ans;
        unordered_map<int,int>map;
        for(int i=0;i<m;i++)
            map[b[i]]++;
        for(int i=0;i<n;i++){
            int f = x-a[i];
            if(map.find(f)!=map.end())
                ans.push_back({a[i],f});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }





