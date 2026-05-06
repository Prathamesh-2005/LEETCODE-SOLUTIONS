class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> grid(m, vector<char>(n));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                grid[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        n = grid.size();
        m = grid[0].size();

        for(int j = 0; j < m; j++)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                if(grid[i][j] == '.')
                {
                    int k = i - 1;

                    while(k >= 0)
                    {
                        if(grid[k][j] == '*')
                        {
                            break;
                        }

                        if(grid[k][j] == '#')
                        {
                            swap(grid[k][j], grid[i][j]);
                            break;
                        }

                        k--;
                    }
                }
            }
        }

        return grid;
    }
};