class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st;
        int ans=0;
        unordered_map<char,int>mp;
        for(auto& c:word)
        {
            if(isupper(c))
            {
                st.insert(c);
            }
        }

        for(auto& c:word)
        {
            if(islower(c))
            {
               char ch=toupper(c);
               mp[c]++;
               if(st.find(ch)!=st.end())
               {
                   if(mp[c]==1)
                   {
                       ans++;
                   }
               }
            }
        }

        return ans;
    }
};