class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.length();
        int col=(n)/rows;
        vector<vector<char>>grid(rows,vector<char>(col,' '));
        int idx=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                grid[i][j]=encodedText[idx++];
            }
        }

        string ans="";

        for(int k=0;k<col;k++)
        {
            int i=0;
            int j=k;

            while(i<rows && j<col)
            {
                ans+=grid[i][j];
                i++;
                j++;
            }
        }
        cout<<ans<<endl;
        
        int i=ans.length()-1;

        while(i>=0 && ans[i]==' ')
        {
            ans.pop_back();
            i--;
        }
        return ans;
    }
};