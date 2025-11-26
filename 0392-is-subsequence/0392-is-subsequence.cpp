class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.length();
        int i=0;
        int j=0;

        while(j<n)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        if(i==s.length())
        {
            return true;
        }
        return false;
    }
};