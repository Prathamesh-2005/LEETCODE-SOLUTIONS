class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int ans=0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<=prev)
            {
                int need=prev+1;
                ans+=(need-nums[i]);
                prev=need;
            }else{
                prev=nums[i];
            }
        }
        return ans;
    }
};