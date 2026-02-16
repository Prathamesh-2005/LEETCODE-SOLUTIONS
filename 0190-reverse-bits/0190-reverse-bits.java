class Solution {
    public int reverseBits(int n) {
        //easy pizzy
        int ans=0;

        for(int i=0;i<=31;i++)
        {
            ans=ans<<1;
            int last=n&1;
            ans=ans | last;
            n=n>>1;
        }
        return ans;
    }
}