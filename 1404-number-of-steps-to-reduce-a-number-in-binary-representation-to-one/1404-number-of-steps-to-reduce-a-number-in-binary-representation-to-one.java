class Solution {
    public int generate(String s)
    {
        int num=0;
        int n=s.length();
        int pow=0;
        for(int i=n-1;i>=0;i--)
        {
            int c=s.charAt(i)-'0';
            num+=(c<<pow);
            pow++;
        }
        System.out.print(num);
        return num;
    }
    public int numSteps(String s) {
        int n=s.length();
        int ans=0;
        int num=generate(s);
        while(num!=1)
        {
            if((num & 1)==1)
            {
                num+=1;
            }else{
                num/=2;
            }
            ans++;
        }
        return ans;
    }
}