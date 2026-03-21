class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==x && j==y)
                {
                    for(int p=j;p<j+k;p++)
                    {
                        for(int q=i;q<=i+k;q++)
                        {

                        }
                        reverse(grid[p].begin(),grid[p].end());
                    }
                }
            }
        }
        return grid;
    }
};