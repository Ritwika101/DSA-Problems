
class Solution {
public:
    int solve(vector<int>& prices, int i, int canBuy, int t[100001][2], int fee)
    {
        if(i>=prices.size())
            return 0;
        if(t[i][canBuy]!=-1)
            return t[i][canBuy];
        int idle=solve(prices,i+1,canBuy,t,fee);
        if(canBuy)
        {
            int buy=-prices[i]+solve(prices,i+1,0,t,fee);
            return t[i][canBuy]=max(buy,idle);
        }
        else
        {
            int sell=prices[i]+solve(prices,i+1,1,t,fee)-fee;
            return t[i][canBuy]=max(idle,sell);
        }
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int t[100001][2];
        memset(t,-1,sizeof(t));
        return solve(prices, 0,1,t,fee);
    }
};
