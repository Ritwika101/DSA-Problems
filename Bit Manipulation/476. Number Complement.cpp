int findComplement(int num) {
        int ans=0;
        int n = num;
        int mask=0;
        while(mask<n){
            mask=mask<<1;
            mask = mask | 1;
        }
        int tilda=~num;
        ans=tilda&mask;
        return ans;
    }
