class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int n=costs.size();
        int i=0;

        while(i<n && coins>0)
        {
            if(coins>=costs[i])
            {
                coins-=costs[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};