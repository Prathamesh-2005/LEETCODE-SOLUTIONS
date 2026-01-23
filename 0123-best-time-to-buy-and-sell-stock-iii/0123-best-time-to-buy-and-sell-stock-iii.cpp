class Solution {
public:
    int solve(int idx,int buy,int cnt,vector<int>& prices)
    {
        if(idx==prices.size())
        {
            return 0;
        }
        if(cnt==0)
        {
            return 0;
        }
        int profit=0;

        if(buy)
        {
            profit=max(-prices[idx]+solve(idx+1,0,cnt,prices),0+solve(idx+1,1,cnt,prices));
        }else{
            profit=max(prices[idx]+solve(idx+1,1,cnt-1,prices),0+solve(idx+1,0,cnt,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,2,prices);
    }
};