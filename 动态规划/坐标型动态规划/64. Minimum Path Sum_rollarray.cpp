class Solution {
public:
    //滚动数组法
    int minPathSum(vector<vector<int>>& grid) {
        //开一个数组, f[i][i] 表示到达f[i][j]的最小总和
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0) return 0;
        vector<vector<int>> f(2, vector<int>(n));

        //two pointers
        //where is i stored:now
        //where is i -1 stored: old
        int now = 0;
        int old = 0;
        for (int i = 0; i < m; i ++) {
            //swap now and old
            old = now;
            now = 1 - old; // 1--> 0 , 0 --> 1
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    //初始化
                    f[now][j] = grid[i][j];
                    continue;
                }

                //记得加上grid[i][j]
                if (i == 0 ) {
                    f[now][j] = f[now][j - 1] + grid[i][j];
                    continue;
                }

                if (j == 0 ) {
                    f[now][j] = f[old][j] + grid[i][j];
                    continue;
                }

                f[now][j] = min(f[old][j], f[now][j - 1]) + grid[i][j];
            }
        }
        return f[now][n -1];
    }
};