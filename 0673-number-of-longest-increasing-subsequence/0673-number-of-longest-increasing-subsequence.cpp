class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        int len=1;
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        len=max(len,dp[i]);
                        cnt[i]=cnt[j];
                    }
                   else if(nums[j]<nums[i] && dp[i]==dp[j]+1)
                    {
                        cnt[i]+=cnt[j];
                    }
                } 
            }
        }

        for(int i=0;i<n;i++)
        {
            if(dp[i]==len)
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};