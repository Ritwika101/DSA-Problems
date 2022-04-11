class Solution {
public:
    int solve(vector<int>& prices, int i, int canBuy, int transCount,int t[100001][2])
    {
        if(i>=prices.size() || transCount<=0)
            return 0;
        if(t[i][canBuy]!=-1)
            return t[i][canBuy];
        int idle=solve(prices,i+1,canBuy,transCount,t);
        if(canBuy)
        {
            int buy=-prices[i]+solve(prices,i+1,0,transCount,t);
            return t[i][canBuy]=max(buy,idle);
        }
        else
        {
            int sell=prices[i]+solve(prices,i+1,1,transCount-1,t);
            return t[i][canBuy]=max(idle,sell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int t[100001][2];
        memset(t,-1,sizeof(t));
        return solve(prices, 0, 1,1,t);
    }
};
