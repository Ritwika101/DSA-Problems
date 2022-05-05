
int reverse(int x) {
        int ans=0;
        vector<int>res;
        while(x!=0)
        {
            int r=x%10;
            if(ans<=INT_MIN/10 || ans>=INT_MAX/10)
                return 0;
            ans = (ans*10)+r;
            x=x/10;
        }
        return ans;
    }
