class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int dig=i-j;
                mp[dig].push_back(grid[i][j]);
            }
        }
        for(auto& it:mp)
        {
            if(it.first>=0)
            {
                sort(it.second.begin(),it.second.end());
            }else{
                sort(it.second.rbegin(),it.second.rend());
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int dig=i-j;
                grid[i][j]=mp[dig].back();
                mp[dig].pop_back();
            }
        }
        return grid;
    }
};