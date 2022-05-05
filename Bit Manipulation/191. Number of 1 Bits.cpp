int hammingWeight(uint32_t n) {
        ll ans=0;
        while(n!=0){
            int bit=n&1;
            if(bit)
                ans++;
            n = n>>1;
        }
        return ans;
    }
