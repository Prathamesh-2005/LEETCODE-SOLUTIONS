class Solution {
public:
    void solve(int idx,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& tmp)
    {
        
            if(target==0)
            {
                ans.push_back(tmp);
                return ;
            }

        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }

            if(candidates[i]<=target)
            {
                tmp.push_back(candidates[i]);
                solve(i+1,candidates,target-candidates[i],ans,tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // set<vector<int>>st;

        sort(candidates.begin(),candidates.end());
        vector<int>tmp;
        vector<vector<int>>ans;
        solve(0,candidates,target,ans,tmp);

        return ans;

    }
};