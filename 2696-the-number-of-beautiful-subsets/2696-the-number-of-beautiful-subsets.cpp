class Solution {
public:
    void solve(int idx,vector<int>& nums,unordered_map<int,int>& mp,int k,int& ans)
    {
        if(idx>=nums.size())
        {
            ans++;
            return ;
        }

        solve(idx+1,nums,mp,k,ans);

        if(!mp[nums[idx]+k] && !mp[nums[idx]-k])
        {
            mp[nums[idx]]++;
            solve(idx+1,nums,mp,k,ans);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;

        solve(0,nums,mp,k,ans);

        return ans-1;
    }
};