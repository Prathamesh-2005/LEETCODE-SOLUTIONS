class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>& sub,set<vector<int>>& st)
    {
        if(sub.size()>=2)
        {
            st.insert(sub); 
        }

        for(int i=idx;i<nums.size();i++)
        {
            if(sub.empty() || nums[i]>=sub.back())
            {
                sub.push_back(nums[i]);
                solve(nums,i+1,sub,st);
                sub.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> sub;
        solve(nums,0,sub,st);

        return vector<vector<int>>(st.begin(), st.end());
    }
};
