class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        int ans=0;
        unordered_map<char,int>mp2;
        unordered_map<char,priority_queue<int>>mp1;
        set<char>st;
        for(int i=0;i<n;i++)
        {
            char c=word[i];
            if(islower(c))
            {
                mp2[c]++;
                mp1[c].push(i);
            }
        }
        // AbBCab
        //b-> 1,5
        for(int i=0;i<n;i++)
        {
            char c=word[i];
            if(isupper(c))
            {
                char ch=tolower(c);
                if(st.find(c)==st.end())
                {  
                    if(mp2.find(ch)!=mp2.end())
                   {
                        auto pq=mp1[ch];
                        int idx=pq.top();
                        if(idx<i)
                        {
                            ans++;
                        }
                }
                }
                st.insert(c);
            }
        }

        return ans;
    }
};