class Solution {
public:

    int solve(int idx, vector<int>& arr, int d, int n,
              vector<int>& dp)
    {
        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        int ans = 1;

        for(int i = idx - 1; i >= max(0, idx - d); i--)
        {
            if(arr[i] >= arr[idx])
            {
                break;
            }

            ans = max(ans,
                      1 + solve(i, arr, d, n, dp));
        }

        for(int i = idx + 1; i <= min(n - 1, idx + d); i++)
        {
            if(arr[i] >= arr[idx])
            {
                break;
            }

            ans = max(ans,
                      1 + solve(i, arr, d, n, dp));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans,
                      solve(i, arr, d, n, dp));
        }

        return ans;
    }
};