class Solution {
public:

    


    int solve(string &str1, string &str2,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j]){
            return dp[i][j] = 1+solve(str1,str2,i-1,j-1,dp);
        }
        return dp[i][j]=max(solve(str1,str2,i-1,j,dp),solve(str1,str2,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,r,n-1,n-1,dp);
    }
};