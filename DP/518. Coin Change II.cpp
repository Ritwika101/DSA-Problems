int t[301][5001];
     int solve(int n, int amount, vector<int>& coins){
        if(n==0)
            return t[n][amount] = 0;
        if(amount==0)
            return t[n][amount] = 1;
        if(t[n][amount]!=-1)
            return t[n][amount];
        if(coins[n-1]<=amount){
                return t[n][amount] = solve(n,amount-coins[n-1],coins)+solve(n-1,amount,coins);
        }
        else
            return t[n][amount] = solve(n-1,amount, coins);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(n,amount,coins);
    }
