class Solution {
public:
    string solve(string& curr,int n,int& k,vector<bool>& visit,string& ans)
    {
        if(curr.size()==n)
        {
            k=k-1;
            if(k==0)
            {
                ans=curr;
            }
            // cout<<curr;
            return "";
        }
        for(int i=1;i<=n;i++)
        {
            if(visit[i])
            {
                continue;
            }
            visit[i]=true;
            curr.push_back(i+'0');
            solve(curr,n,k,visit,ans);
            curr.pop_back();
            visit[i]=false;
        }
        return "";
    }
    string getPermutation(int n, int k) {
        vector<bool>visit(n+1,false);
        string curr="";
        string ans="";
        solve(curr,n,k,visit,ans);
        return ans;
    }
};