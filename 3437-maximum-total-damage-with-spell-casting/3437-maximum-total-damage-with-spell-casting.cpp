#define ll long long 
class Solution {
public:
    ll solve(int idx, vector<int>& power, vector<ll>& total, vector<ll>& dp) {
        if(idx >= power.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int next = lower_bound(power.begin(), power.end(), power[idx] + 3) - power.begin();

        ll pick = total[idx] + solve(next, power, total, dp);
        ll skip = solve(idx + 1, power, total, dp);

        return dp[idx] = max(pick, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        map<int,ll> freq;
        for(int p : power) freq[p] += p;

        vector<int> tmp;
        vector<ll> total;
        for(auto &it : freq) {
            tmp.push_back(it.first);
            total.push_back(it.second);
        }

        int n = tmp.size();
        vector<ll> dp(n, -1);
        return solve(0, tmp, total, dp);
    }
};
