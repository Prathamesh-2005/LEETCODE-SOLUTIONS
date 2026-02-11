class Solution {
    public boolean check(int mid,int []nums,int m,int k)
    {
        int n=nums.length;
        int cnt=0;
        int adj=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=mid)
            {
                adj++;
                if(adj==k)
                {
                    cnt++;
                    adj=0;
                }
            }else{
                adj=0;
            }
        }
        return cnt>=m;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int n=bloomDay.length;
        if((long)m*k>n)
        {
            return -1;
        }
        int ans=0;
        int l=0,h=0;
        for(int num:bloomDay)
        {
            l=Math.min(num,l);
        }
        for(int num:bloomDay)
        {
            h=Math.max(num,h);
        }

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(check(mid,bloomDay,m,k))
            {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
}