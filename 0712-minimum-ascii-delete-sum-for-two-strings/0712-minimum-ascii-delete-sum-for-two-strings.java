class Solution {
    public int lcs(String s1,String s2)
    {
        int n=s1.length();
        int m=s2.length();
        int [][]dp=new int[n+1][m+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1))
                {
                    dp[i][j]=s1.charAt(i-1)+dp[i-1][j-1];
                }else
                {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
   public int calculate(String s)
   {
     int ans=0;
       for(int i=0;i<s.length();i++)
       {
         ans+=s.charAt(i);
       }
       return ans;
   }
   public int minimumDeleteSum(String s1, String s2) {
    int temp = lcs(s1, s2);

    int asc1=calculate(s1);
    int asc2=calculate(s2);
    int ans=asc1+asc2-2*temp;
    return ans;
}
}