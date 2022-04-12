long long countAtmostKDistinct(string &s, int k) {
        // write your code here
        unordered_map<char,ll>m;
        int rel = 0;
        ll distinct=0;
        ll ans=0;
        ll n=s.length();
        if(k==0)
            return 0;
    	for(ll acq=0;acq<n;acq++){
        	if(m[s[acq]]==0)
            		distinct+=1;
        	m[s[acq]]+=1;
        	while(rel<acq && distinct>k){
            		m[s[rel]]-=1;
            		if(m[s[rel]]==0)
                		distinct-=1;
            		rel+=1;
        	}
        	ans+=(acq-rel+1);
    	}
	return ans;
    }
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        ll n=s.length();
	    ll totalSubs = n*(n+1)/2;
	    ll atmostK = countAtmostKDistinct(s,k-1);
	    ll atleastK = totalSubs - atmostK;
	    return atleastK;
    }
