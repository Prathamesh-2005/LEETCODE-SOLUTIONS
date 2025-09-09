class Solution {
public:
    int m = 1e9 + 7;
    vector<int> dp;

    int solve(int day, int forget, int delay) {
        if (day == 1) return 1;
        if (dp[day] != -1) return dp[day];

        long long ans = 0;
        for (int i = day - forget + 1; i <= day - delay; i++) {
            if (i > 0) {
                ans = (ans + solve(i, forget, delay)) % m;
            }
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.assign(n + 1, -1);
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i > 0) {
                ans = (ans + solve(i, forget, delay)) % m;
            }
        }
        return ans;
    }
};
