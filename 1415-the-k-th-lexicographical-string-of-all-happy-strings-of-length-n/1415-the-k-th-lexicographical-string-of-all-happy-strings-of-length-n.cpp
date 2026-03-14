class Solution {
public:
    string ans="";
    string solve(int n,int k,string curr,int cnt)
    {
        if(curr.length()==n)
        {
            cnt++;
            if(cnt==k)
            {
                ans=curr;
            }
        }
        for(char c='a';c<='c';c++)
        {
            if(curr.length()>0 && curr.back()==c)
            {
                continue;
            }
            curr.push_back(c);
            solve(n,k,curr,cnt);
            curr.pop_back();
        }
        return ans;
    }
    string getHappyString(int n, int k) {
        string curr="";
        return solve(n,k,curr,0);
    }
};