class Solution {
public:  
    int solve(int idx,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp)
    {
        int n=prices.size();
        if(idx==n)
        {
            return 0;
        }
        if(dp[idx][buy]!=-1)
        {
            return dp[idx][buy];
        }
        int profit=0;

        if(buy)
        {
            profit=max(-prices[idx]+solve(idx+1,0,fee,prices,dp),0+solve(idx+1,1,fee,prices,dp));
        }else{
            profit=max(prices[idx]+solve(idx+1,1,fee,prices,dp)-fee,0+solve(idx+1,0,fee,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,fee,prices,dp);
    }
};