class Solution {
public:
    void solve(int idx,vector<int>& nums,int k,vector<vector<int>>& ans,vector<int>& temp,int n)
    {
            if(temp.size()==k)
            {
                ans.push_back(temp);
                return ;
            }


        for(int i=idx;i<=n;i++)
        {
            temp.push_back(nums[i]);
            solve(i+1,nums,k,ans,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n+1,0);
        for(int i=1;i<=n;i++)
        {
            nums[i]=i;
        }

        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,nums,k,ans,temp,n);
        return ans;
    }
};