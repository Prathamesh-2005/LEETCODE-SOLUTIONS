class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int res = INT_MAX;

            int next = vec[(idx + 1) % vec.size()];
            int dist1 = abs(next - q);
            dist1 = min(dist1, n - dist1);

            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int dist2 = abs(prev - q);
            dist2 = min(dist2, n - dist2);

            res = min(dist1, dist2);

            ans.push_back(res);
        }

        return ans;
    }
};