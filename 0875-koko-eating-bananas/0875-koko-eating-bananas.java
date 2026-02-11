class Solution {
    public boolean check(int [] nums,int k,int h)
    {
        long cnt=0;
        int n=nums.length;
        for(int i=0;i<n;i++)
        {
            cnt+=(nums[i]/k);

            if(nums[i]%k!=0)
            {
                cnt++;
            }
        }
        return cnt<=h;
    }
    public int minEatingSpeed(int[] piles, int hour) {
        int n=piles.length;
        int ans=Integer.MAX_VALUE;
        
        int l=1;
        int h=0;
        for(int num:piles)
        {
            h=Math.max(h,num);
        }

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(check(piles,mid,hour))
            {
                ans=mid;
                h=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        return ans;
    }
}