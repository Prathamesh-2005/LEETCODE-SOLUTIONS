class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        if (n <= x) {
            int sum = 0;
            for (auto& i : nums) {
                sum += i;
            }
            return {sum};
        }
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mpp;
            for (int j = i; j < i + k; j++) {
                mpp[nums[j]]++;
            }
            vector<pair<int, int>> temp(mpp.begin(), mpp.end());
            sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second > b.second;
            });
            int topx = 0;
            for (int j = 0; j < x && j < temp.size(); j++) {
                topx += temp[j].first * temp[j].second;
            }
            res.push_back(topx);
        }
        return res;
    }
};