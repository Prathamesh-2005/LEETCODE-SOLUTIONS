class Solution {
public:
    int n;
    int dp[201][1001];
    int solve(int idx,vector<int>& nums,int target)
    {
        if(target==0)
        {
            return 1;
        }

        if(target<0 || idx>=n)
        {
            return 0;
        }

        if(dp[idx][target]!=-1)
        {
            return dp[idx][target];
        }

        // int pick=solve(0,nums,target-nums[idx]);
        // int non_pick=solve(idx+1,nums,target);

        int res=0;
        for(int i=idx;i<n;i++)
        {
            int pick=solve(0,nums,target-nums[i]);
            res+=pick;
        }

        return dp[idx][target]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);
    }
};