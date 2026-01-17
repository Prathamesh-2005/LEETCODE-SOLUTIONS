class Solution {
public:
    bool check(int i,int j)
    {
        return (i%j==0 || j%i==0);
    }
    void solve(vector<int>& nums,int i,int prev,vector<int>& ans,vector<int>& curr)
    {
        if(i==nums.size())
        {
            if(curr.size()>ans.size())
            {
                ans=curr;
            }
            return ;
        }
        if(prev==-1 || check(nums[i],nums[prev]))
        {
            curr.push_back(nums[i]);
            solve(nums,i+1,i,ans,curr);
            curr.pop_back();
        }
        return solve(nums,i+1,prev,ans,curr);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int idx=0;
        int len=1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }

                    if(len<dp[i])
                    {
                        len=dp[i];
                        idx=i;
                    }
                }
            }
        }

        while(idx!=-1)
        {
            ans.push_back(nums[idx]);
            idx=prev[idx];
        }
        return ans;
    }
};