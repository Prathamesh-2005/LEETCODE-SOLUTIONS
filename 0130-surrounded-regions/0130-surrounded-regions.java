class Solution {
    int direc[][]={{-1,0},{0,-1},{1,0},{0,1}};
   public void dfs(int i, int j, boolean[][] vis, char[][] board) {
        int n = board.length, m = board[0].length;
        vis[i][j] = true;

        for (int[] d : direc) {
            int I = i + d[0];
            int J = j + d[1];
            if (I >= 0 && I < n && J >= 0 && J < m &&
                !vis[I][J] && board[I][J] == 'O') {
                dfs(I, J, vis, board);
            }
        }
    }

    public void solve(char[][] board) {
        int n=board.length;
        int m=board[0].length;
        boolean vis[][]=new boolean[n][m];

        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                dfs(0,j,vis,board);
            }

            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,vis,board);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
}