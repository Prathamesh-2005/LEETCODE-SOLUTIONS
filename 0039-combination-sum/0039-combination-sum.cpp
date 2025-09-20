class Solution {
public:
    void solve(int idx,int target,vector<int>& nums,vector<vector<int>>& ans,vector<int>& tmp)
    {
        if(idx==nums.size())
        {
            if(target==0)
            {
                ans.push_back(tmp);
            }
            return ;
        }

        if(nums[idx]<=target)
        {
            tmp.push_back(nums[idx]);
            solve(idx,target-nums[idx],nums,ans,tmp);
            tmp.pop_back();
        }

        solve(idx+1,target,nums,ans,tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tmp;    
        solve(0,target,candidates,ans,tmp);

        return ans;
    }
};