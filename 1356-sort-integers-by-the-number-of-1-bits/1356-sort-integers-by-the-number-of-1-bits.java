class Solution {
    public boolean check(int n1,int n2)
    {
        int cnt1=0,cnt2=0;
        int num1=n1,num2=n2;
        while(n1>0)
        {
            if( (n1 & 1)==1)
            {
                cnt1++;
            }
            n1>>=1;
        }
        while(n2>0)
        {
            if( (n2 & 1)==1)
            {
                cnt2++;
            }
            n2>>=1;
        }
        if(cnt1>cnt2)
        {
            return true;
        }else if(cnt1==cnt2)
        {
            return num1>num2;
        }
        return false;
    }
    public int[] sortByBits(int[] arr) {
        int n=arr.length;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(check(arr[j],arr[j+1]))
                {
                    int tmp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=tmp;
                }
            }
        }
        return arr;
    }
}