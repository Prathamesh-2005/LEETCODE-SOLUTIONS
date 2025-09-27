class Solution {
public:
    int n;
    void solve(int idx,string& s,int& ans,unordered_set<string>& st)
    {
        if(idx==n)
        {
            ans=max(ans,(int)st.size());
            return ;
        }

        for(int i=idx;i<n;i++)
        {
            string temp=s.substr(idx,i-idx+1);
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                solve(i+1,s,ans,st);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        unordered_set<string>st;
        int ans=INT_MIN;
        int idx=0;
        string curr="";
        solve(idx,s,ans,st);

        return ans;
    }
};