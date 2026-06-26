class Solution {
public:
    bool check(string s,int idx1,int idx2)
    {
        int i=idx1;
        int j=idx2;

        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string &s,vector<vector<string>>& ans,vector<string>& curr)
    {
        if(idx==s.length())
        {
            ans.push_back(curr);
            return ;
        }

        for(int j=idx;j<s.length();j++)
        {
            if(check(s,idx,j))
            {
                curr.push_back(s.substr(idx,j-idx+1));
                solve(j+1,s,ans,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,s,ans,curr);
        return ans;
    }
};