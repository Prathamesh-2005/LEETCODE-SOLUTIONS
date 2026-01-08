class Solution {
public:
    int ans;
    int dp[1001][1001];
    int solve(vector<int>& nums1,vector<int>& nums2,int i,int j)
    {
        if(i==nums1.size() || j==nums2.size())
        {
            return -1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int pick1=nums1[i]*nums2[j];
        pick1=max(pick1,nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1));
        int pick2=solve(nums1,nums2,i,j+1);
        int pick3=solve(nums1,nums2,i+1,j);

        return dp[i][j]=max({pick1,pick2,pick3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        ans=solve(nums1,nums2,0,0);
        return ans;
    }
};