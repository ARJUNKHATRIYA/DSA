class Solution {
  public:
    int solve(int i,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(i==wt.size()){
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int not_take = solve(i+1,W,val,wt,dp);
        int take = INT_MIN;
        if(wt[i]<=W){
            take = val[i]+solve(i+1,W-wt[i],val,wt,dp);
        }
        return dp[i][W]= max(take,not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code heretre
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(0,W,val,wt,dp);
        
    }
};