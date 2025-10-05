class Solution {
    int solve(int i, int j, int[][] matrix, int[][] dp) {
        int n = matrix.length;
        int m = matrix[0].length;
        final int INF = (int) 1e9;

        if (j < 0 || j >= m) return INF;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != Integer.MAX_VALUE) return dp[i][j];

        int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        int left = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        int right = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);

        return dp[i][j] = Math.min(up, Math.min(left, right));
    }

    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int ans = Integer.MAX_VALUE;
        int[][] dp = new int[n][m];

        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);

        for (int j = 0; j < m; j++) {
            ans = Math.min(ans, solve(n - 1, j, matrix, dp));
        }

        return ans;
    }
}
