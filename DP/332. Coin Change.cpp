class Solution {
int t[13][10001];
public:
    int solve(int n, int amount, vector<int>& coins){
        if(n==0)
            return INT_MAX;
        if(amount==0)
            return 0;
        if(t[n][amount]!=-1)
            return t[n][amount];
        if(coins[n-1]<=amount){
            int x = solve(n,amount-coins[n-1],coins);
            if(x!=INT_MAX)
                return t[n][amount] = min(1+x, solve(n-1,amount,coins));
            else
                return t[n][amount] = solve(n-1,amount,coins);
        }
        else
            return t[n][amount] = solve(n-1,amount, coins);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        int x =  solve(n,amount,coins);
        if(x==INT_MAX)
            return -1;
        else
            return x;
    }
};
