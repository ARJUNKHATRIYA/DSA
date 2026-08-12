class Solution {
public:
    // int solve(int i){
    //     if(i==0 || i==1) return 1;
    //     return solve(i-1)+solve(i-2);
    // }
    //  int solve(int i,vector<int>&dp){
    //     if(i==0 || i==1) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     return solve(i-1,dp)+solve(i-2,dp);
    // }
    int climbStairs(int n) {
        // if (n == 0 || n == 1) return 1;

        // int prev1 = 1; // Ways to reach step 1
        // int prev2 = 1; // Ways to reach step 0

        // for (int i = 2; i <= n; ++i) {
        //     int current = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = current;
        // }

        // return prev1;
        // return solve(n);
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
