class Solution {
public:
    void set(vector<vector<int>>& matrix,int row,int col,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==row || j==col)
                {
                    matrix[i][j]=0;
                }
            }
        }   
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        unordered_set<int>st1,st2;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    st1.insert(i);
                    st2.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(st1.count(i) && st2.count(j))
                {
                    set(matrix,i,j,n,m);
                }
            }
        }
    }
};