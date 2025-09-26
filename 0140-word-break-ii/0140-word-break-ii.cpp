class Solution {
public:
    int n;
    void solve(int idx,string& s,vector<string>& ans,unordered_set<string>& st,string& curr)
    {
        if(idx>=n)
        {
            ans.push_back(curr);
            return ;
        }

        for(int j=idx;j<n;j++)
        {
            string temp=s.substr(idx,j-idx+1);
            string tem=curr;  //store the curr sentence so that we can explore and undo 
            if(st.find(temp)!=st.end())
            {
                if(!curr.empty())
                {
                    curr+=" ";
                }
                curr+=temp;
                solve(j+1,s,ans,st,curr);
                curr=tem;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        vector<string>ans;
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        string curr="";
        solve(0,s,ans,st,curr);

        return ans;
    }
};