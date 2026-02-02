class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>mp;
            int cnt=0;
            int len=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target)
                {
                    cnt++;
                }
                len=j-i+1;
                if(cnt>len/2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};