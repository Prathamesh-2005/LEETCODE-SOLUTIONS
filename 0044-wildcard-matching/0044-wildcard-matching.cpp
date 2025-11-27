class Solution {
public:
    bool solve(string s, string p, int i, int j, int n, int m,
               vector<vector<int>>& dp) {
        if (i < 0 && j < 0) {
            return true;
        }

        if (j < 0 && i >= 0) {
            return false;
        }

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, n, m, dp);
        }

        if (p[j] == '*') {
            return dp[i][j] = solve(s, p, i, j - 1, n, m, dp) ||
                              solve(s, p, i - 1, j, n, m, dp);
        }

        return false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};