class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //开一个数组, f[i][i] 表示到达f[i][j]的最小总和
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0) return 0;
        vector<vector<int>> f(grid);

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    //初始化
                    f[i][j] = grid[i][j];
                    continue;
                }

                //记得加上grid[i][j]
                if (i == 0 ) {
                    f[i][j] = f[i][j - 1] + grid[i][j];
                    continue;
                }

                if (j == 0 ) {
                    f[i][j] = f[i - 1][j] + grid[i][j];
                    continue;
                }

                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m -1][n -1];
    }
};