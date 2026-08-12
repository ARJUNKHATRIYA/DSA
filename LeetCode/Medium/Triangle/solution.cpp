class Solution {
public:
    // recusrion
    // int solve(int i,int j,vector<vector<int>>& triangle){
    //     if(i==triangle.size()-1){
    //        return triangle[i][j];
    //     }
       
    //     int down = triangle[i][j]+solve(i+1,j,triangle);
    //     int diagonal =triangle[i][j]+solve(i+1,j+1,triangle);
    //     return min(down,diagonal);
    // }

    // memoization
    //     int solve(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>&dp){
    //     if(i==triangle.size()-1){
    //        return triangle[i][j];
    //     }
    //     if (dp[i][j] != -1)
    //     return dp[i][j];
       
    //     int down = triangle[i][j]+solve(i+1,j,triangle,dp);
    //     int diagonal =triangle[i][j]+solve(i+1,j+1,triangle,dp);
    //     return min(down,diagonal);
    // }

    // tabulation
        int solve(vector<vector<int>>& triangle){
            int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                 int down =
                dp[i + 1][j];

            int diagonal =
                dp[i + 1][j + 1];

            dp[i][j] =
                triangle[i][j]
                + min(
                    down,
                    diagonal
                );
            }
        }
        return dp[0][0];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(0,0,triangle,dp);
        return solve(triangle);
    }
};