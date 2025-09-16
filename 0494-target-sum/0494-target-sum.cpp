class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);

        if ((sum + diff) < 0 || (sum + diff) % 2 != 0) 
            return 0;
            
        int target=(sum+diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        dp[0][0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};