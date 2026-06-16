class Solution {
public:
    string processStr(string s) {
        string ans="";
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                if(ans.length()>=1)
                {
                    ans.erase(ans.length()-1,1);
                }
            }else if(s[i]=='#')
            {
                ans+=ans;
            }else if(s[i]=='%')
            {
                reverse(ans.begin(),ans.end());
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};