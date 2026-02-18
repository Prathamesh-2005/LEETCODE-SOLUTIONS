class Solution {
    public int longestSubarray(int[] nums) {
        int n=nums.length;
        int ans=2;
        int curr=2;

        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[i-1]+nums[i-2])
            {
                curr++;
            }else
            {
                ans=Math.max(ans,curr);
                curr=2;
            }
        }
        return Math.max(ans,curr);

    }
}