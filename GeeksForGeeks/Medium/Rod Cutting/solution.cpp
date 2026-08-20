class Solution {
  public:
    
    int solve(int i,vector<int> &price,int length,vector<vector<int>>&dp){
        int n= price.size();
        
        if(length<=0) return 0;
        if (i > n)
        return 0;
        if(dp[i][length]!=-1) return dp[i][length];
        
        int not_take = solve(i+1,price,length,dp);
        int take  = 0;
        if(length>=i){
            take = price[i-1]+solve(i,price,length-i,dp);
        }
        return dp[i][length]= max(take,not_take);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n= price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,price,n,dp);
        
    }
};