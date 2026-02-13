class Solution {
public:
    int solve(string& s,char ch1,char ch2)
    {
        int n=s.length();
        int cnt1=0;
        int cnt2=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=ch1 && s[i]!=ch2)
            {
                mp.clear();
                cnt1=0;
                cnt2=0;
                continue;
            }

            if(s[i]==ch1)
            {
                cnt1++;
            }
            if(s[i]==ch2)
            {
                cnt2++;
            }

            if(cnt1==cnt2)
            {
                ans=max(ans,cnt1+cnt2);
            }
            int diff=cnt1-cnt2;
            if(mp.find(diff)!=mp.end())
            {
                ans=max(ans,i-mp[diff]);
            }
            else{
                mp[diff]=i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;

        //case 1 : any 1 contribute to answer 
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);

        //case 2 : any 2 chars contribute to answer 
        ans=max(ans,solve(s,'a','b'));
        ans=max(ans,solve(s,'b','c'));
        ans=max(ans,solve(s,'a','c'));

        //case 3 : all chars contribute to answer 
        unordered_map<string,int>mp;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                cnt1++;
            }
            if(s[i]=='b')
            {
                cnt2++;
            }
            if(s[i]=='c')
            {
                cnt3++;
            }

            if(cnt1==cnt2 && cnt1==cnt3)
            {
                ans=max(ans,cnt1+cnt2+cnt3);
            }
            string key=to_string(cnt1-cnt2)+"-"+to_string(cnt1-cnt3);

            if(mp.find(key)!=mp.end())
            {
                ans=max(ans,i-mp[key]);
            }
            else{
                mp[key]=i;
            }
        }
        return ans;
    }
};