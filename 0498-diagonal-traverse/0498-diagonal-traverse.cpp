class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        for (int d = 0; d < n + m - 1; d++) {
            if (d % 2 == 0) {
                reverse(mp[d].begin(), mp[d].end());
            }
            for (int x : mp[d]) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};