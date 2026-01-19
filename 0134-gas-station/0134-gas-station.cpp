class Solution {
public:
    //     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int n = gas.size();

    //     for (int i = 0; i < n; i++) {
    //         int curr = 0;
    //         bool ok = true;

    //         for (int j = 0; j < n; j++) {
    //             int k = (i + j) % n;   
    //             curr += gas[k];

    //             if (curr < cost[k]) {
    //                 ok = false;
    //                 break;
    //             }
    //             curr -= cost[k];
    //         }

    //         if (ok) return i;
    //     }
    //     return -1;
    // }
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
