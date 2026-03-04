class Solution {
public:
    bool check(int row,int col,vector<vector<int>>& mat,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]==1 && i!=row)
            {
                return false;
            }
        }

        for(int j=0;j<m;j++)
        {
            if(mat[row][j]==1 && j!=col)
            {
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if(check(i,j,mat,n,m))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};