class Solution {
public:
    int find(unordered_map<char,int>& mp)
    {
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(auto& m:mp)
        {
            mx=max(mx,m.second);
            mn=min(mn,m.second);
        }
        return mx-mn;
    }
    int beautySum(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                int beauty=find(mp);
                ans+=beauty;
            }
        }
        return ans;
    }
};