class Solution {
public:
    void solve(vector<int>& ip,vector<int>& op,vector<vector<int>>& ans)
    {
        if(ip.size()==0)
        {
            ans.push_back(op);
            return ;
        }
        for(int i=0;i<ip.size();i++)
        {
            vector<int>op1=op;
            vector<int>ip1=ip;
            op1.push_back(ip1[i]);
            ip1.erase(ip1.begin()+i);
            solve(ip1,op1,ans);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>op;
        solve(nums,op,ans);
        return ans;
    }
};