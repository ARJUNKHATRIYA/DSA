class Solution {
public:
    int solve( vector<int>& prices, int i,int buy,vector<vector<int>>&dp) {
        int n = prices.size();

        if (i >= n)
            return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        if (buy) {
            int buystock = -prices[i] + solve(prices, i + 1, 0, dp);
            int skip = solve(prices, i + 1, 1, dp);
            return dp[i][buy] = max(buystock, skip);
        } else {
            int sell = prices[i] + solve(prices, i + 2, 1, dp);
            int skip = solve(prices, i + 1, 0, dp);
            return dp[i][buy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};