class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum1=accumulate(gas.begin(),gas.end(),0);
        int sum2=accumulate(cost.begin(),cost.end(),0);

        if(sum1<sum2)
        {
            return -1;
        }
        int ans=0,curr=0;

        for(int i=0;i<n;i++)
        {
            curr+=gas[i]-cost[i];

            if(curr<0)
            {
                ans=i+1;
                curr=0;
            }
        }
        return ans;
    }
};
