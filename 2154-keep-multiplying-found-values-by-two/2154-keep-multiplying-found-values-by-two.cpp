class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans=original;
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.find(ans)!=st.end())
        {
            ans*=2;
        }
        return ans;
    }
};