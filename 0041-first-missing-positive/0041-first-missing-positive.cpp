class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int>st(nums.begin(),nums.end());
        int mn=*st.begin();
        int mx=*st.end();
        for(int i=1;i<=mx+1;i++)
        {
            if(st.find(i)==st.end())
            {
                return i;
            }
        }

        return -1;
    }
};