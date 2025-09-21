class Solution {
public:
    unordered_map<char,string>mp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void solve(int idx,string ip,string op,vector<string>& ans)
    {
        if(idx==ip.length())
        {
            if(!op.empty())
            ans.push_back(op);
            return ;
        }

        if(idx>ip.length())
        {
            return ;
        }
        char ch=ip[idx];
        string str=mp[ch];

        for(int i=0;i<str.length();i++)
        {
            op.push_back(str[i]);
            solve(idx+1,ip,op,ans);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string op="";
        int idx=0;
        solve(idx,digits,op,ans);
        return ans;
    }
};