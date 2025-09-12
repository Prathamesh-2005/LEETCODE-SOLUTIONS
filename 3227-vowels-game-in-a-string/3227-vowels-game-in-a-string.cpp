class Solution {
public:
    bool isvowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    bool doesAliceWin(string s) {
        int n=s.length();
        int cnt=0;

        for(auto& c:s)
        {
            if(isvowel(c))
            {
                cnt++;
            }
        }
        if(cnt==0)
        {
            return false;
        }
        if(cnt & 1)
        {
            return true;
        }
        return true;
    }
};