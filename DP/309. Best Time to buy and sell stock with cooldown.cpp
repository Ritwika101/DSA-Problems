class Solution {
public:
    int solve(vector<int>& prices, int i, int canBuy, vector<vector<int>>&t)
    {
        if(i>=prices.size())
            return 0;
        if(t[i][canBuy]!=-1)
            return t[i][canBuy];
        int idle=solve(prices,i+1,canBuy,t);
        if(canBuy)
        {
            int buy=-prices[i]+solve(prices,i+1,0,t);
            return t[i][canBuy]=max(buy,idle);
        }
        else
        {
            int sell=prices[i]+solve(prices,i+2,1,t);
            return t[i][canBuy]=max(idle,sell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
      
        vector<vector<int>>t(prices.size()+1,vector<int>(2,-1));
        return solve(prices, 0,1,t);
    }
};
