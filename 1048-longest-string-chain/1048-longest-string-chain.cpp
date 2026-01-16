class Solution {
public:
    bool check(string s,string p)
    {
        if(p.length()!=s.length()+1)
        {
            return false;
        }
        int i=0,j=0;
        bool flag=false;

        while(i<s.length() && j<p.length())
        {
            if(s[i]==p[j])
            {
                i++;
                j++;
            }else{
                if(!flag)
                {
                    j++;
                    flag=true;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
    int solve(int i,int prev,vector<string>& words)
    {
        if(i==words.size())
        {
            return 0;
        }

        int pick=0;

        if(prev==-1 || check(words[prev],words[i]))
        {
            pick=1+solve(i+1,i,words);
        }
        int not_pick=solve(i+1,prev,words);

        return max(pick,not_pick);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& a,string& b)
        {
            return a.length()<b.length();
        });

        vector<int>dp(words.size(),1);

        int ans=1;

        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }

        return ans;
    }
};