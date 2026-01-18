class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>row(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            row[i][0]=grid[i][0];
            for(int j=1;j<m;j++)
            {
                row[i][j]=row[i][j-1]+grid[i][j];
            }
        }

        vector<vector<int>>col(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            col[0][j]=grid[0][j];
            for(int i=1;i<n;i++)
            {
                col[i][j]=col[i-1][j]+grid[i][j];
            }
        }

        for(int side=min(n,m);side>=2;side--)
        {
            for(int i=0;i+side-1<n;i++)
            {
                for(int j=0;j+side-1<m;j++)
                {
                    int target=row[i][j+side-1]-(j>0 ? row[i][j-1]:0);

                    bool flag=true;

                    for(int r=i+1;r<i+side;r++)
                    {
                        int sum=row[r][j+side-1]-(j>0 ? row[r][j-1]:0);
                        if(target!=sum)
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        continue;
                    }

                    for(int c=j;c<j+side;c++)
                    {
                        int sum=col[i+side-1][c]-(i>0 ? col[i-1][c] : 0);

                        if(sum!=target)
                        {
                            flag=false;
                            break;
                        }
                    }

                    if(!flag)
                    {
                        continue;
                    }

                    int diag=0,anti=0;

                    for(int k=0;k<side;k++)
                    {
                        diag+=grid[i+k][j+k];
                        anti+=grid[i+k][j+side-1-k];
                    }

                    if(diag==target && anti==target)
                    {
                        return side;
                    }
                }
            }
        }

        return 1;
    }
};