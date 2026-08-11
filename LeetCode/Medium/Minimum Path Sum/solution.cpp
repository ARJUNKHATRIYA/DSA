class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& grid){
    //     if(i==0 && j==0){
    //         return grid[0][0];
    //     }
    //      if (i < 0 || j < 0) {
    //         return INT_MAX;
    //     }
    //     int up = solve(i-1,j,grid);
    //     int left = solve(i,j-1,grid);
    //     if (up != INT_MAX) {
    //         up += grid[i][j];
    //     }

    //     if (left != INT_MAX) {
    //         left += grid[i][j];
    //     }
    //     return min(up,left);
    // }
    int memoHelper(
    int i,
    int j,
    vector<vector<int>>& grid,
    vector<vector<int>>& dp
) {

    // Starting cell
    if (i == 0 && j == 0)
        return grid[0][0];

    // Outside grid
    if (i < 0 || j < 0)
        return 1e9;

    // Already calculated
    if (dp[i][j] != -1)
        return dp[i][j];

    // From top
    int up =
        grid[i][j]
        + memoHelper(
            i - 1,
            j,
            grid,
            dp
        );

    // From left
    int left =
        grid[i][j]
        + memoHelper(
            i,
            j - 1,
            grid,
            dp
        );

    dp[i][j] =
        min(up, left);

    return dp[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        // int i = grid.size();
        // int j = grid[0].size();
        // return solve(i-1,j-1,grid);
         int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(
        m,
        vector<int>(n, -1)
    );

    return memoHelper(
        m - 1,
        n - 1,
        grid,
        dp
    );
    }
};