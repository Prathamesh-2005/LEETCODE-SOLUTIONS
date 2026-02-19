class Solution {
    public int countBinarySubstrings(String s) {
        int n=s.length();
        int ans=0;
        List<Integer>list =new ArrayList<>();
        int cnt=0;
        int i=0,j=0;
        while(i<n)
        {
            j=i;
            char num=s.charAt(j);
            while(j<n && num==s.charAt(j))
            {
                j++;
                cnt++;
            }
            list.add(cnt);
            i=j;
            cnt=0;
        }
        int m=list.size();

        for(int k=1;k<m;k++)
        {
            ans+=Math.min(list.get(k),list.get(k-1));
        }
        return ans;
    }
}