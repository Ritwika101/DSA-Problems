int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int>m;
        m[0]=0;
        int ans=0,prefix=0;
        for(int i=0;i<n;i++){
            prefix+=a[i];
            if(m.find(prefix)==m.end())
                m[prefix]=1;
            else{
		ans+=m[prefix];
		m[prefix]++;
	    }
        }
        return ans;
    }


