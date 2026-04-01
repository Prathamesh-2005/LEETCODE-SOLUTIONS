class Solution {
public:
    int n, m;

    int dfs(int i, int j, int xori, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        xori ^= grid[i][j];

        if(i == n-1 && j == m-1)
            return xori;

        if(dp[i][j][xori] != -1)
            return dp[i][j][xori];

        int right = INT_MAX, down = INT_MAX;

        if(j + 1 < m)
            right = dfs(i, j+1, xori, grid, dp);

        if(i + 1 < n)
            down = dfs(i+1, j, xori, grid, dp);

        return dp[i][j][xori] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return dfs(0, 0, 0, grid, dp);
    }
};