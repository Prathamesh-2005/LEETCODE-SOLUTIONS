class Solution {
public:
    int ans=0;
    bool check(vector<int>& temp)
    {
        for(auto& t:temp)
        {
            if(t!=0)
            {
                return false;
            }
        }
        return true;
    }
    void solve(int idx,vector<int>& temp,vector<vector<int>>& req,int cnt)
    {
        if(idx==req.size())
        {
            if(check(temp))
            {
                ans=max(ans,cnt);
            }
            return ;
        }
        int from=req[idx][0];
        int to=req[idx][1];

        //pick
        temp[from]--;
        temp[to]++;
        solve(idx+1,temp,req,cnt+1);

        //Non Pick
        temp[from]++;
        temp[to]--;
        solve(idx+1,temp,req,cnt);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n,0);
        solve(0,temp,requests,0);
        return ans;
    }
};