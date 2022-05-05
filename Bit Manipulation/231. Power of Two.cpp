bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int count=0;
        int ans = n&(n-1);
        if(!ans)
            return true;
        return false;    
    }
