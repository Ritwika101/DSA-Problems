vector<int> intersect(vector<int>& a, vector<int>& b) {
        int l1=a.size();
        int l2=b.size();
        vector<int>ans;
        unordered_map<int,int>m;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0, j=0;
        
        while(i<l1 && j<l2){
            if(a[i]<b[j])
                i++;
            else if(a[i]>b[j])
                j++;
            else if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
