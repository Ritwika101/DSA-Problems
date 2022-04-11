class Solution {
public:
    int solve(vector<int>& prices, int i, int canBuy, int transCount, vector<vector<vector<int>>>&t)
    {
        if(i>=prices.size() || transCount<=0)
            return 0;
        if(t[i][canBuy][transCount]!=-1)
            return t[i][canBuy][transCount];
        int idle=solve(prices,i+1,canBuy,transCount,t);
        if(canBuy)
        {
            int buy=-prices[i]+solve(prices,i+1,0,transCount,t);
            return t[i][canBuy][transCount]=max(idle,buy);
        }
        else
        {
            int sell=prices[i]+solve(prices,i+1,1,transCount-1,t);
            return t[i][canBuy][transCount]=max(idle,sell);
        }     
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>t(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,t);
    }
};
