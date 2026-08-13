class Solution {
public:
    bool solve(vector<int>& nums,int i,int sum1,int sum2,vector<vector<int>>&dp){
        int n = nums.size();
        if(sum1==sum2){
            return true;
        }
        if(i==n){
            return false;
        }
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        bool take = solve(nums,i+1,sum1+nums[i],sum2-nums[i],dp);
        bool nottake = solve(nums,i+1,sum1,sum2,dp);
        return dp[i][sum1]=take||nottake ;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(total+1,-1));

        return solve(nums,0,0,total,dp);
    }
};