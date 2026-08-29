class Solution {
public:
    int solve( vector<int>& prices, int i,int buy,int k,vector<vector<vector<int>>>&dp) {
        int n = prices.size();

        if (i == n || k==0)
            return 0;
        
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if (buy) {
            int buystock = -prices[i] + solve(prices, i + 1, 0,k, dp);
            int skip = solve(prices, i + 1, 1,k, dp);
            return dp[i][buy][k] = max(buystock, skip);
        } else {
            int sell = prices[i] + solve(prices, i + 1, 1,k-1, dp);
            int skip = solve(prices, i + 1, 0,k, dp);
            return dp[i][buy][k] = max(sell, skip);
        }
    }

        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
            return solve(prices,0,1,k,dp);
        }
    };