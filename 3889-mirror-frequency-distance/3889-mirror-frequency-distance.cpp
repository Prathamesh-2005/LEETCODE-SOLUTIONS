class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>mp;

        for(auto& c:s)
        {
            mp[c]++;
        }

        string miro="";

        for(auto& c: s)
        {
            if(isalpha(tolower(c)))
            {
                char m='a'+('z'-c);
                miro+=m;
            }else{
                int dig=9-(c-'0');
                char m=dig+'0';
                miro+=m;
            }
        }
        // cout<<miro<<endl;

        int ans=0;
        unordered_set<char>st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(st.find(ch)!=st.end() || st.find(miro[i])!=st.end())
            {
                continue;
            }
            ans+=(abs(mp[ch]-mp[miro[i]]));
            st.insert(ch);
            st.insert(miro[i]);
        }
        return ans;
    }
};