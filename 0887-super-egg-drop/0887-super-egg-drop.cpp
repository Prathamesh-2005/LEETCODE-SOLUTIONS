class Solution {
public:
    int dp[101][10001];

    int solve(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 1) return f;

        if (dp[e][f] != -1) return dp[e][f];

        int low = 1, high = f;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            int breaks = solve(e - 1, mid - 1);
            int no_break = solve(e, f - mid);

            int temp = 1 + max(breaks, no_break);
            ans = min(ans, temp);

            if (breaks < no_break) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return dp[e][f] = ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};
