class Solution {
public:
    int change(int amount, vector<int>& coins) {
        using u128 = unsigned __int128;  // safer large integer type
        
        int n = coins.size();
        vector<vector<u128>> dp(n+1, vector<u128>(amount+1, 0));

        // base case: ways to make sum 0 = 1
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][amount]; // final answer fits in int
    }
};
