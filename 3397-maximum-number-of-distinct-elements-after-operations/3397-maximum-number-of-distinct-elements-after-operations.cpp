class Solution {
public:
    // int solve(int num,int k,unordered_set<int>& st)
    // {
    //     for(int i=-k;i<=k;i++)
    //     {
    //         if(st.find(i + num) == st.end())
    //         {
    //             return i + num;
    //         }
    //     }
    //     return INT_MAX;
    // }

    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cur = INT_MIN / 2;
        int ans = 0;
        for (int x : nums) {
            int num = max(cur + 1, x - k);
            if (num <= x + k) {
                cur = num;
                ans++;
            }
        }
        return ans;
    }
};
