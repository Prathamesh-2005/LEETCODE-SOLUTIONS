class Solution {
    public boolean check(int []weights,int mid,int days)
    {
        int sum=0,cnt=1;
        int n=weights.length;
        for(int i=0;i<n;i++)
        {
            if(sum+weights[i]<=mid)
            {
                sum+=weights[i];
            }else{
                cnt++;
                sum=weights[i];
            }
        }
        return cnt<=days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int n=weights.length;
        int ans=0;
        int l=0,h=0;

        for(int num:weights)
        {
            l=Math.max(l,num);
            h+=num;
        }

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(check(weights,mid,days))
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