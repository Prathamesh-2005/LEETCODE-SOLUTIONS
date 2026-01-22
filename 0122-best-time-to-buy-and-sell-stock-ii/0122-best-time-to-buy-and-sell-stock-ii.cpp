class Solution {
public:
    int solve(int idx,int buy,vector<int>& prices)
    {
        if(idx==prices.size())
        {
            return 0;
        }

        int ans=0;

        if(buy)
        {
            ans=max(-prices[idx]+solve(idx+1,0,prices),0+solve(idx+1,1,prices));
        }else{
            ans=max(prices[idx]+solve(idx+1,1,prices),0+solve(idx+1,0,prices));
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
    }
};