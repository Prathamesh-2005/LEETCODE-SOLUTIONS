class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        if((mx+1)!=n)
        {
            return false;
        }
        vector<int>good;
        for(int i=1;i<=mx;i++)
        {
            good.push_back(i);
        }
        good.push_back(mx);
        sort(nums.begin(),nums.end());
        return good==nums;
    }
};