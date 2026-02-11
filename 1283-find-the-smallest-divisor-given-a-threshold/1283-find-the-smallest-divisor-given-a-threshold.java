class Solution {
    public boolean check(int mid,int []nums,int threshold)
    {
        int n=nums.length;
        int []arr=new int [n];
        for(int i=0;i<n;i++)
        {
            arr[i]=(int)Math.ceil((double)nums[i]/mid);
        }
        int sum=0;
        for(int num:arr)
        {
            sum+=num;
        }
        return sum<=threshold;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int n=nums.length;
        int ans=0;
        int l=1;
        int h=0;
        for(int num:nums)
        {
            h=Math.max(num,h);
        }

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(check(mid,nums,threshold))
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