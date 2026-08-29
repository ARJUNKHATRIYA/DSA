class Solution {
public:

    bool solve(
        string &s,
        string &p,
        int i,
        int j,
        vector<vector<int>> &dp
    ) {

        // Both string and pattern are exhausted
        if(i < 0 && j < 0)
            return true;

        // Pattern exhausted but string remains
        if(j < 0)
            return false;

        // String exhausted
        if(i < 0) {

            // Remaining pattern must contain only '*'
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*')
                    return false;
            }

            return true;
        }

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // '*' case
        if(p[j] == '*') {

            // Two choices:
            //
            // 1. '*' matches s[i]
            //    -> i-1, j
            //
            // 2. '*' matches empty
            //    -> i, j-1

            return dp[i][j] =
                solve(s, p, i - 1, j, dp) ||
                solve(s, p, i, j - 1, dp);
        }

        // Normal character or '?'
        if(s[i] == p[j] || p[j] == '?') {

            return dp[i][j] =
                solve(s, p, i - 1, j - 1, dp);
        }

        // No match
        return dp[i][j] = false;
    }


    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(
            s,
            p,
            n - 1,
            m - 1,
            dp
        );
    }
};