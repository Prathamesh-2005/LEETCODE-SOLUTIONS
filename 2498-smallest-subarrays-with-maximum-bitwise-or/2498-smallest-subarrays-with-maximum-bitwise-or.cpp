class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        vector<int>set(32,-1);

        for(int i=n-1;i>=0;i--)
        {
            int idx=i;

            for(int j=0;j<32;j++)
            {
                if(!(nums[i]&(1<<j)))
                {
                    if(set[j]!=-1)
                    {
                        idx=max(idx,set[j]);
                    }
                }
                else{
                    set[j]=i;
                }
            }
            ans[i]=idx-i+1;
        }
        return ans;
    }
};