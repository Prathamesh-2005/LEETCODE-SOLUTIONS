class Solution {
    int count(int num)
    {
        int cnt=0;

        while(num!=0)
        {
            if((num & 1)==1)
            {
                cnt++;
            }
            num>>=1;
        }
        return cnt;
    }
    public List<String> readBinaryWatch(int turnedOn) {
        List<String>ans=new ArrayList<>();
        
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(count(i)+count(j)==turnedOn)
                {
                    String hh=String.valueOf(i);
                    String mm=(j<10 ? "0" : "") + j;
                    String time=hh + ":" + mm;
                    ans.add(time);
                }
            }
        }
        return ans;
    }
}