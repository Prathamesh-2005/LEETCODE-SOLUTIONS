class Solution {
public:
    int solve(int idx,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(idx==prices.size())
        {
            return 0;
        }
        if(cnt==0)
        {
            return 0;
        }
        if(dp[idx][buy][cnt]!=-1)
        {
            return dp[idx][buy][cnt];
        }
        int profit=0;

        if(buy)
        {
            profit=max(-prices[idx]+solve(idx+1,0,cnt,prices,dp),0+solve(idx+1,1,cnt,prices,dp));
        }else{
            profit=max(prices[idx]+solve(idx+1,1,cnt-1,prices,dp),0+solve(idx+1,0,cnt,prices,dp));
        }
        return dp[idx][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};