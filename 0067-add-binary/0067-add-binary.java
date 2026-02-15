class Solution {
    public String addBinary(String a, String b) {
        int n=a.length();
        int m=b.length();
        StringBuilder sb=new StringBuilder();
        int i=n-1;
        int j=m-1;
        int sum=0,carry=0;

        while(i>=0 || j>=0 || carry!=0)
        {
            int num1=(i<0 ? 0: a.charAt(i)-'0');
            int num2=(j<0 ? 0 : b.charAt(j)-'0');
            int curr=num1+num2+carry;
            sum=(curr)%2;
            carry=curr/2;
            sb.append(sum);
            i--;
            j--;
        }
        sb.reverse();
        return sb.toString();
    }
}