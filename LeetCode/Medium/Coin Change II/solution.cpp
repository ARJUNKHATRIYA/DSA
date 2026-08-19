class Solution {
public:
    vector<vector<int>> ans;
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {

        if(amount==0){
            return 1;
        }
        if(idx==coins.size()) return amount==0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take=0;
        if(coins[idx]<=amount){
            take = solve(coins,amount-coins[idx],idx,dp);
        }
        
        int not_take = solve(coins,amount,idx+1,dp);
        return dp[idx][amount]=take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int idx = coins.size();
        
        vector<vector<int>> dp(idx, vector<int>(amount + 1, -1));
        int x = solve(coins, amount, 0, dp);
        return x;
    }
};