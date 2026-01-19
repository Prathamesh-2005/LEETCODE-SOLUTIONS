class Solution {
public: 
    bool solve(string s,int cnt,int idx)
    {
        if(cnt<0)
        {
            return false;
        }
        if(idx==s.length())
        {
            if(cnt==0)
            {
                return true;
            }
            return false;
        }
        if(s[idx]=='(')
        {
            return solve(s,cnt+1,idx+1);
        }
        if(s[idx]==')')
        {
            return solve(s,cnt-1,idx+1);
        }
        
        return solve(s,cnt+1,idx+1) || solve(s,cnt-1,idx+1) || solve(s,cnt,idx+1);
    }
    bool checkValidString(string s) {
        int n=s.length();
        int mn=0,mx=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                mn=mn+1;
                mx=mx+1;
            } 
            else if(s[i]==')')
            {
                mn=mn-1;
                mx=mx-1;
            }
            else if(s[i]=='*')
            {
                mn=mn-1;
                mx=mx+1;
            }
            if(mn<0)
            {
                mn=0;
            }
            if(mx<0)
            {
                return false;
            }
        }

        return (mn==0);
    }
};