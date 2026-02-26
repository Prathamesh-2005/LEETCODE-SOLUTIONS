class Solution {
    // public int generate(String s)
    // {
    //     int num=0;
    //     int n=s.length();
    //     int pow=0;
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         int c=s.charAt(i)-'0';
    //         num+=(c<<pow);
    //         pow++;
    //     }
    //     System.out.print(num);
    //     return num;
    // }
    public void add(StringBuilder sb)
    {
        int n=sb.length();
        StringBuilder ans=new StringBuilder();
        StringBuilder one=new StringBuilder("1");
        int carry=0;
        int i=n-1,j=one.length()-1,sum=0;
        while(i>=0 || j>=0 || carry!=0)
        {
            int num1=(i<0 ? 0 : sb.charAt(i)-'0'); 
            int num2=(j<0 ? 0 : one.charAt(j)-'0'); 
            int curr=num1+num2+carry;
            sum=(curr%2);
            carry=curr/2;
            ans.append(sum);
            i--;
            j--;
        }
        ans.reverse();
        sb.setLength(0);
        sb.append(ans);
    }
    public int numSteps(String s) {
        int n=s.length();
        int ans=0;
        StringBuilder sb=new StringBuilder(s);
        while(!sb.toString().equals("1"))
        {
            if(sb.charAt(sb.length()-1)=='0')
            {
                sb.deleteCharAt(sb.length()-1);
            }else{
                add(sb);
            }
            ans++;
        }
        return ans;
    }
}