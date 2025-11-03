class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int idx = 0; 

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[idx]) {
                ans += min(neededTime[i], neededTime[idx]);
                if (neededTime[i] > neededTime[idx]) {
                    idx = i;
                }
            } else {
                idx = i;
            }
        }

        return ans;
    }
};
