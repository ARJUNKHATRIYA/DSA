class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int cap,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(i==n || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap] = max(-prices[i]+solve(prices,i+1,0,cap,dp),solve(prices,i+1,1,cap,dp));

        }else{
            return dp[i][buy][cap] = max(prices[i]+solve(prices,i+1,1,cap-1,dp),solve(prices,i+1,0,cap,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp);
    }
};