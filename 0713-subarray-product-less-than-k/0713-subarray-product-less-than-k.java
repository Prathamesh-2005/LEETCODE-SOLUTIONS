class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k<=1)
        {
            return 0;
        }
        int ans=0;
        int n=nums.length;
        int i=0,j=0;
        long prod=1;
        while(j<n)
        {
            prod*=(long)nums[j];
            while(i<n && prod>=k)
            {
                prod=prod/nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
}