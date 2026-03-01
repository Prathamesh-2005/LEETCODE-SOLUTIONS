class Solution {
public:
    bool check(int row,int col,vector<string>& board)
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }

        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void solve(int row,vector<string>& board,int& ans)
    {
        if(row==board.size())
        {
            ans++;
            return ;
        }
        for(int col=0;col<board.size();col++)
        {
            if(check(row,col,board))
            {
                board[row][col]='Q';
                solve(row+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string>board(n,string(n,'.'));
        solve(0,board,ans);
        return ans;
    }
};