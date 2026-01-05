class Solution {
public:
    int dp[500][500];
    int solve(int i,int j,vector<int>& nums)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int temp=solve(i,k-1,nums)+solve(k+1,j,nums)+(nums[i-1]*nums[k]*nums[j+1]);
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(1,n-2,nums);
    }
};