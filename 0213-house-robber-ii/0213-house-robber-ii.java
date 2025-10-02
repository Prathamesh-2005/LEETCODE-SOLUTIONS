class Solution {
    public int solve(int idx,int []nums,int n,int []dp)
    {
        if(idx>n)
        {
            return 0;
        }

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int take=nums[idx]+solve(idx+2,nums,n,dp);
        int not=solve(idx+1,nums,n,dp);
        return dp[idx]=Math.max(take,not);
    }
    public int rob(int[] nums) {
        int n=nums.length;

        if(n==1)
        {
            return nums[0];
        }
        int [] dp1=new int[n];
        Arrays.fill(dp1,-1);
        int first=solve(0,nums,n-2,dp1);
        int [] dp2=new int[n];
        Arrays.fill(dp2,-1);
        int second=solve(1,nums,n-1,dp2);
        return Math.max(first,second);
    }
}