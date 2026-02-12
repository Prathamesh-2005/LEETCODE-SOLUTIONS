class Solution {
public:
    bool check(unordered_map<char,int>& mp)
    {
        int freq=mp.begin()->second;

        for(auto& m:mp)
        {
            if(m.second!=freq)
            {
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                if(check(mp))
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};