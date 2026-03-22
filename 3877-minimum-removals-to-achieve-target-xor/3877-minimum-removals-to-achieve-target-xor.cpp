class Solution {
public:
    int dp[41][100000];
    int solve(vector<int>& nums,int target,int idx,int xo)
    {
        if(idx==nums.size())
        {
            if(xo==target)
            {
                return 0;
            }else{
                return 1e9;
            }
        }
        if(dp[idx][xo]!=-1)
        {
            return dp[idx][xo];
        }
        int take=0;
        int not_take=0;

        take=0+solve(nums,target,idx+1,xo^nums[idx]);
        not_take=1+solve(nums,target,idx+1,xo);
        return dp[idx][xo]=min(take,not_take);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,target,0,0);
        return (ans==1e9 ? -1 : ans);
    }
};