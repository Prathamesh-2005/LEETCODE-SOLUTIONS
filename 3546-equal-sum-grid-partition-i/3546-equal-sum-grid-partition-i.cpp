class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        ll sum{0},sum1{0},sum2{0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=grid[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum1+=grid[i][j];
                if(sum1==(sum-sum1))
                {
                    return true;
                }
            }
        }

        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                sum2+=grid[i][j];

                if(sum2==(sum-sum2))
                {
                    return true;
                }
            }
        }

        return false;
    }
};