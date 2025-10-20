class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //Total sum
        //minimum sum  why ???  circularSum=total-min
        int n=nums.size();
        int total=nums[0];
        int mn=nums[0];
        int mx=nums[0];
        int sum1=nums[0];  //for min
        int sum2=nums[0];  // for max
        for(int i=1;i<n;i++)
        {
            total+=nums[i];
            sum1=min(nums[i],sum1+nums[i]);
            mn=min(mn,sum1);

            sum2=max(nums[i],sum2+nums[i]);
            mx=max(mx,sum2);
        }

        int circular=total-mn;

        if(mx>0)
        {
           return  max(circular,mx);
        }

        return mx;
    }
};