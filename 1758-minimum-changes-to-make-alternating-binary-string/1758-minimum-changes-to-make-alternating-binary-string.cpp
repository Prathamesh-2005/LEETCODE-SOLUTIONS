class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                ans++;
                s[i]= (s[i-1]=='1' ? '0' :'1');
            }
        }
        return ans;
    }
};