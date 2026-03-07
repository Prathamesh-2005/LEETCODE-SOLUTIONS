class Solution {
public:
    int minFlips(string s) {
        int m=s.length();
        s=s+s;
        int n=s.length();
        int ans=INT_MAX;

        string s1="";
        string s2="";
        for(int i=0;i<n;i++)
        {
            s1+= (i & 1) ? '1' : '0';
            s2+= (i & 1) ? '0' : '1';
        }
        int i{0};
        int j{0};
        int tmp1{0};
        int tmp2{0};
        while(j<n)
        {
            if(s1[j]!=s[j])
            {
                tmp1++;
            }

            if(s2[j]!=s[j])
            {
                tmp2++;
            }

            if(j-i+1>m)
            {
                if(s1[i]!=s[i])
                {
                    tmp1--;
                }

                if(s2[i]!=s[i])
                {
                    tmp2--;
                }
                i++;
            }
            if(j-i+1==m)
            {
                ans=min(ans,min(tmp1,tmp2));
            }
            j++;
        }
        return ans;
    }
};