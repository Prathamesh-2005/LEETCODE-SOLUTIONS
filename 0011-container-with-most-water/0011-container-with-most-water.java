class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int i=0;
        int j=n-1;
        int ans=Integer.MIN_VALUE;
        while(i<j)
        {
            int wid=j-i;
            int ht=Math.min(height[i],height[j]);
            int area=ht*wid;
            ans=Math.max(area,ans);

            if(height[i]<height[j])
            {
                i++;
            }
            else{
                j--;
            }
        }

        return ans;
    }
}