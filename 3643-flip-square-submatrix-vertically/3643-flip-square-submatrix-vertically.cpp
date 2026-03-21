class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int row=x+k-1;
        int col=y+k-1;

        for(int i=x;i<=row;i++)
        {
            for(int j=y;j<=col;j++)
            {
                swap(grid[i][j],grid[row][j]);
            }
            row--;
        }
        return grid;
    }
};