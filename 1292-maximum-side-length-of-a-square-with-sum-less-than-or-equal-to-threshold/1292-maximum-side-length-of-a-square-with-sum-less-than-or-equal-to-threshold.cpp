class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> row(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            row[i][0] = mat[i][0];
            for (int j = 1; j < m; j++) {
                row[i][j] = row[i][j - 1] + mat[i][j];
            }
        }

        int low = 0, high = min(n, m), ans = 0;

        while (low <= high) {
            int side = (low + high) / 2;
            bool flag = false;

            for (int i = 0; i + side - 1 < n && !flag; i++) {
                for (int j = 0; j + side - 1 < m; j++) {

                    int sum = 0;
                    for (int r = i; r < i + side; r++) {
                        sum += row[r][j + side - 1] -
                               (j > 0 ? row[r][j - 1] : 0);
                    }

                    if (sum <= threshold) {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) {
                ans = side;
                low = side + 1;  
            } else {
                high = side - 1;  
            }
        }

        return ans;
    }
};
