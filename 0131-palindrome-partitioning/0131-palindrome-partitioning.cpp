class Solution {
public:
    bool palindrome(string& s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(int idx,string ip,vector<string>& op,vector<vector<string>>& ans)
    {
        if(idx==ip.length())
        {
            ans.push_back(op);
        }

        for(int i=idx;i<ip.length();i++)
        {
            if(palindrome(ip,idx,i))
            {
                op.push_back(ip.substr(idx,i-idx+1));
                solve(i+1,ip,op,ans);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>op;
        int idx=0;
        solve(idx,s,op,ans);

        return ans;
    }
};