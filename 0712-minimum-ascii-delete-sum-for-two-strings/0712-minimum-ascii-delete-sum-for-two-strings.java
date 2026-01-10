class Solution {
    public String lcs(String s1,String s2)
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
                    dp[i][j]=1+dp[i-1][j-1];
                }else
                {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        StringBuilder ans=new StringBuilder();

        while(i>0 && j>0)
        {
            if(s1.charAt(i-1)==s2.charAt(j-1))
            {
                ans.append(s1.charAt(i-1));
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else{
                j--;
            }
        }
        ans.reverse();
        System.out.println(ans.toString());

        return ans.toString();
    }
    public int minimumDeleteSum(String s1, String s2) {
        string temp=lcs(s1,s2);
        int ans=0;
        int i=0,j=0;
        int n=s1.length();
        int m=s2.length();
        while(i<temp.length())
        {
            if(temp.charAt(i)!=s1.charAt(j))
            {
                ans+=s1.charAt(j);
                j++;
            }
            else{
                i++;
                j++;
            }
        }

        if(j!=n)
        {
            for(int k=j;k<n;k++)
            {
                ans+=s1.charAt(k);
            }
        }
        
    }
}