class Solution {
    public boolean check(int mid,int m,int []position)
    {
        int cnt=1;
        int last=position[0];

        for(int i=1;i<position.length;i++)
        {
            if(position[i]-last>=mid)
            {
                cnt++;
                last=position[i];
            }
        }
        return cnt>=m;
    }
    public int maxDistance(int[] position, int m) {
        int n=position.length;
        int ans=0;
        Arrays.sort(position);
        int l=1,h=(int)1e9;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(check(mid,m,position))
            {
                l=mid+1;
                ans=mid;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
}