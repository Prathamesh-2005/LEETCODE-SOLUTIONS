class Solution {
    public int solve(int idx, int[] nums, int n, int[] dp) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int take = nums[idx] + solve(idx + 2, nums, n, dp);
        int notTake = solve(idx + 1, nums, n, dp);

        return dp[idx] = Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return solve(0, nums, n, dp);
    }
}
