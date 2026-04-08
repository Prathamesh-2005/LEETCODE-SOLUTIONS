class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        int mod=1e9+7;
        for(auto& q:queries)
        {
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];

            int idx=l;

            while(idx<=r)
            {
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }

        for(auto& num:nums)
        {
            ans^=num;
        }
        return ans;
    }
};