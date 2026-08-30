class Solution {
public:
    int solve( vector<int>& prices, int i,int buy,vector<vector<int>>&dp,int fee) {
        int n = prices.size();

        if (i >= n)
            return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        if (buy) {
            int buystock = -prices[i] + solve(prices, i + 1, 0, dp,fee);
            int skip = solve(prices, i + 1, 1, dp,fee);
            return dp[i][buy] = max(buystock, skip);
        } else {
            int sell = prices[i]-fee + solve(prices, i + 1, 1, dp,fee);
            int skip = solve(prices, i + 1, 0, dp,fee);
            return dp[i][buy] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return solve(prices,0,1,dp,fee);
    }
};