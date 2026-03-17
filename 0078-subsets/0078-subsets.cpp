class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int total=1<<n;

        for(int i=0;i<total;i++)
        {
            vector<int>tmp;
            for(int j=0;j<n;j++)
            {
                if((i & 1<<j))
                {
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};