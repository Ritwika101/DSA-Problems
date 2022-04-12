vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        int i=0, distinct=0;
        unordered_map<int,int>m;
        vector<int>res;
        int rel = 0;
        
        for(int i=rel;i<k;i++){
            if(m[a[i]]==0)
                distinct++;
            m[a[i]]++;
        }
        res.push_back(distinct);
        for(int acq=k;acq<n;acq++){
            m[a[rel]]--;
            if(m[a[rel]]==0)
                distinct--;
            rel++;
            if(m[a[acq]]==0)
                distinct++;
            m[a[acq]]++;
            res.push_back(distinct);
        }
        return res;
        
    }
