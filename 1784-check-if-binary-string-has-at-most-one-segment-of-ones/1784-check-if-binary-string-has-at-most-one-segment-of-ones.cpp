class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int cnt=0;
        int i=0;

        while(i<n)
        {
            if(s[i]=='1')
            {
                int j=i;
                while(s[j]=='1')
                {
                    j++;
                }
                cnt++;
                i=j;
            }
            i++;
        }
        return cnt==1;
    }
};