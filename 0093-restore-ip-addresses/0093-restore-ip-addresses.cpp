class Solution {
public:
    bool check(string& s)
    {
        if(s.length()==1)
        {
            if(s[0]=='0')
            {
                return true;
            }
        }
        if(s.length()>1)
        {
            if(s[0]=='0')
            {
                return false;
            }
        }
        if(stoi(s)>=0 && stoi(s)<=255)
        {
            return true;
        }
        return false;
    }
    void solve(int idx,int cnt,string& ip,string op,vector<string>& ans)
    {
        if(idx==ip.length() && cnt==4)
        {
            ans.push_back(op);
            return;
        }

        if(cnt>=4)
        {
            return;
        }
        for(int i=idx;i<ip.length() && i-idx<3;i++)
        {
            string temp=ip.substr(idx,i-idx+1);
            if(check(temp))
            {
                solve(i+1, cnt+1, ip, op + (op.empty() ? "" : ".") + temp, ans);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string op="";
        int idx=0;
        int cnt=0;
        solve(idx,cnt,s,op,ans);

        return ans;
    }
};