class Solution {
public:
    int binary_search(vector<int>& nums,int num)
    {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=n;
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(nums[mid]>=num)
            {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int lis(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>sorted;

        for(int i=0;i<n;i++)
        {
            int idx=binary_search(sorted,nums[i]);
            if(idx==sorted.size())
            {
                sorted.push_back(nums[i]);
            }else{
                sorted[idx]=nums[i];
            }
        }

        return sorted.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int j=0;j<=31;j++)
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                if(nums[i] & (1<<j))
                {
                    temp.push_back(nums[i]);
                }
            }
            ans=max(ans,lis(temp));
        }
        return ans;
    }
};