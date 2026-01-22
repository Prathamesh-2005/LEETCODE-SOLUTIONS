class Solution {
public:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx==prices.size())
        {
            return 0;
        }
        if(dp[idx][buy]!=-1)
        {
            return dp[idx][buy];
        }
        int ans=0;
        if(buy)
        {
            ans=max(-prices[idx]+solve(idx+1,0,prices,dp),0+solve(idx+1,1,prices,dp));
        }else{
            ans=max(prices[idx]+solve(idx+1,1,prices,dp),0+solve(idx+1,0,prices,dp));
        }
        return dp[idx][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};