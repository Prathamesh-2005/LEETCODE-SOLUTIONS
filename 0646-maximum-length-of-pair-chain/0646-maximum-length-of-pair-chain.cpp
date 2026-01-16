class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        int ans=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int b=nums[j][1];
                int c=nums[i][0];

                if((b<c || c<b) && b!=c)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }

        return ans;
    }
};