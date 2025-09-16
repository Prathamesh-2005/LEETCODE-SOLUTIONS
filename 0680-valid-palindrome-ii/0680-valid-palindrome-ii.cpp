class Solution {
public:
    bool solve(string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                i++;j--;
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                break;
            }
        }

        if(i>=j)
        {
            return true;
        }
        return solve(s,i+1,j) || solve(s,i,j-1);
    }
};