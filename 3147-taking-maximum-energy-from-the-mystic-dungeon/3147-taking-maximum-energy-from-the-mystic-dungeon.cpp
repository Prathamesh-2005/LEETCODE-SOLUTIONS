class Solution {
public:
    void solve(int idx, vector<int>& energy, int k, int& ans) {
        if(idx >= energy.size()) return;

        int curr = 0;
        int i = idx;

        while(i < energy.size()) {
            curr += energy[i];
            i += k;
        }

        ans = max(ans, curr);

        solve(idx + 1, energy, k, ans);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        solve(0, energy, k, ans);
        return ans;
    }
};
