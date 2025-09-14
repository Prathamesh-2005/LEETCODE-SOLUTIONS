class Solution {
public:
    string toLower(string& str)
    {
        string ans="";
        for(auto& c:str)
        {
            ans+=tolower(c);
        }
        return ans;
    }
    bool isvowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string replace(string& str)
    {
        string ans=str;
        for(int i=0;i<str.length();i++)
        {
            if(isvowel(str[i]))
            {
                ans[i]='*';
            }
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=wordlist.size();
        int m=queries.size();
        vector<string>ans(m);
        unordered_set<string>st(wordlist.begin(),wordlist.end());
        unordered_map<string,string>cas;
        unordered_map<string,string>vow;
        for(auto& q:wordlist)
        {
            string low=toLower(q);

            if(cas.find(low)==cas.end())
            {
                cas[low]=q;
            }
            string tmp=replace(low);
            if(vow.find(tmp)==vow.end())
            {
                vow[tmp]=q;
            }
        }

        for(int i=0;i<m;i++)
        {
            string q=queries[i];
            string low=toLower(q);
            string tmp=replace(low);
            if(st.find(q)!=st.end())
            {
                ans[i]=q;
            }
            else if(cas.find(low)!=cas.end())
            {
                ans[i]=cas[low];
            }
            else if(vow.find(tmp)!=vow.end())
            {
                ans[i]=vow[tmp];
            }
            else{
                ans[i]="";
            }
        }
        return ans;
    }
};